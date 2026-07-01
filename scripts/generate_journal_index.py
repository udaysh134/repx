#!/usr/bin/env python3
"""
Journal Index Generator

This script recursively scans a journal directory for notebook pages,
validates the contents against a metadata YAML file, and generates a
clean, deterministic, and configurable README index.

The README is generated entirely from scratch on every run.
"""

import sys
import difflib
from pathlib import Path
from typing import List, Dict, Set, Tuple, Any
import yaml

# Reconfigure stdout/stderr to support Unicode characters on Windows terminal if possible
if hasattr(sys.stdout, 'reconfigure'):
    try:
        sys.stdout.reconfigure(encoding='utf-8')
    except Exception:
        pass
if hasattr(sys.stderr, 'reconfigure'):
    try:
        sys.stderr.reconfigure(encoding='utf-8')
    except Exception:
        pass

# ==============================================================================
# CONFIGURATION
# ==============================================================================

# Directory containing the journal pages, relative to the repository root
ROOT_DIRECTORY = "docs/journals"

# Filename of the README index to be generated
README_FILENAME = "README.md"

# Filename of the metadata file to read
METADATA_FILENAME = "metadata.yaml"

# File extensions that are considered notebook pages
SUPPORTED_EXTENSIONS = [
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".webp"
]

# Valid status values for the journal pages
STATUS_VALUES = [
    "Historical",
    "Implemented",
    "Partially Implemented",
    "Superseded",
    "Abandoned"
]

# Title of the README document
README_TITLE = "RepX Journal Index"

# Introductory paragraphs for the README
README_INTRODUCTION = [
    "This document serves as the central registry of all RepX design journal pages. Each notebook page captures a stage in the evolution of RepX, ranging from early concepts and architectural decisions to interface designs and implementation notes.",
    "Some pages document ideas that were later refined or replaced, while others describe designs that were eventually implemented. They are preserved to record the engineering journey behind RepX."
]

# Section title of the table section
README_TABLE_TITLE = "📄 Notebook Pages"

# Paragraphs of the closing note (rendered as a callout block)
README_NOTE = [
    "These notebook pages are preserved as historical engineering artifacts. They document the evolution of RepX from its earliest concepts to its current architecture. While many designs were implemented, some pages capture exploratory ideas or intermediate stages that were later refined during development."
]

# Table column headers
TABLE_HEADERS = [
    "**S.No.**",
    "**Page**",
    "**Category**",
    "**Description**",
    "**Status**"
]

# Table column alignments (matching standard Markdown alignments)
# :---: for centered, :--- for left-aligned, ---: for right-aligned
TABLE_ALIGNMENT = [
    ":---:",
    ":---:",
    ":---:",
    ":---",
    ":---:"
]

# Placeholder for missing optional metadata values
MISSING_VALUE = "-"

# Featured section generation control
GENERATE_FEATURED_SECTION = True

# Title of the Featured section
README_FEATURED_TITLE = "⭐ Featured Notebook Pages"

# Description paragraphs for the Featured section
README_FEATURED_DESCRIPTION = [
    "The following pages represent key milestones, core concepts, or foundational architectural designs of RepX."
]

# Featured table column headers
FEATURED_TABLE_HEADERS = [
    "**S.No.**",
    "**Page**",
    "**Category**",
    "**Reason**",
    "**Status**"
]

# Featured table column alignments
FEATURED_TABLE_ALIGNMENT = [
    ":---:",
    ":---:",
    ":---:",
    ":---",
    ":---:"
]

# Dynamic journal summary template strings
README_SUMMARY_TEMPLATE = "This document currently indexes {total} design journal pages, including {featured} featured notebook pages and {regular} additional notebook pages."
README_SUMMARY_TEMPLATE_NO_FEATURED = "This document currently indexes {total} design journal pages."

# Minimum similarity ratio (0.0 to 1.0) to warn about potential file renames
SIMILARITY_THRESHOLD = 0.70


# ==============================================================================
# IMPLEMENTATION
# ==============================================================================

def resolve_path(relative_path: str) -> Path:
    """
    Resolves a path relative to the repository root.
    If the path is already absolute, returns it as-is.
    """
    path = Path(relative_path)
    if path.is_absolute():
        return path
    
    # Assume the repository root is the parent directory of this script's folder
    repo_root = Path(__file__).resolve().parent.parent
    return (repo_root / path).resolve()


def scan_directory(dir_path: Path, supported_exts: List[str]) -> List[Path]:
    """
    Recursively scans dir_path for notebook page files.
    Ignores:
    - Files named README_FILENAME or METADATA_FILENAME
    - Hidden files and folders (names starting with '.')
    - Empty folders or directories with no supported notebook pages (implicitly)
    
    Sorts files and subdirectories alphabetically at each level to ensure
    consistent and deterministic results.
    """
    if dir_path.name.startswith("."):
        return []

    files: List[Path] = []
    subdirs: List[Path] = []

    try:
        for entry in dir_path.iterdir():
            if entry.name.startswith("."):
                continue
            if entry.is_file():
                if entry.name in (README_FILENAME, METADATA_FILENAME):
                    continue
                if entry.suffix.lower() in supported_exts:
                    files.append(entry)
            elif entry.is_dir():
                subdirs.append(entry)
    except OSError as e:
        print(f"Warning: Could not read directory {dir_path}: {e}", file=sys.stderr)
        return []

    # Sort alphabetically for determinism
    files.sort(key=lambda p: p.name)
    subdirs.sort(key=lambda p: p.name)

    result: List[Path] = []
    # Add files at the current level first
    result.extend(files)
    # Recursively traverse subdirectories
    for subdir in subdirs:
        result.extend(scan_directory(subdir, supported_exts))

    return result


def validate_metadata(
    metadata: Any,
    scanned_files: List[Path],
    journals_dir: Path
) -> Tuple[List[str], List[str], List[str], List[str]]:
    """
    Validates metadata contents and directory structure.
    Returns a tuple of:
    - malformed_errors: Errors related to invalid format of metadata
    - missing_metadata: Paths of filesystem files that have no metadata
    - metadata_without_file: Names of files in metadata that do not exist on disk
    - invalid_status_filenames: Filenames with invalid status values
    """
    malformed_errors: List[str] = []
    missing_metadata: List[str] = []
    metadata_without_file: List[str] = []
    invalid_status_filenames: List[str] = []

    # 1. Structure / Malformed check
    if not isinstance(metadata, dict):
        malformed_errors.append("Metadata root is not a dictionary/object.")
        return malformed_errors, missing_metadata, metadata_without_file, invalid_status_filenames

    if "files" not in metadata:
        malformed_errors.append("Metadata is missing 'files' key.")
        return malformed_errors, missing_metadata, metadata_without_file, invalid_status_filenames

    files_section = metadata["files"]
    if not isinstance(files_section, dict):
        malformed_errors.append("'files' key in metadata must be a dictionary mapping filenames to details.")
        return malformed_errors, missing_metadata, metadata_without_file, invalid_status_filenames

    # Validate each metadata entry structure
    metadata_filenames = set()
    for filename, data in files_section.items():
        metadata_filenames.add(filename)
        if not isinstance(data, dict):
            malformed_errors.append(f"Metadata entry for '{filename}' must be a dictionary/object.")
            continue
        
        if "description" in data and data["description"] is not None:
            if not isinstance(data["description"], str):
                malformed_errors.append(f"Description for '{filename}' must be a string.")

        if "status" in data and data["status"] is not None:
            if not isinstance(data["status"], str):
                malformed_errors.append(f"Status for '{filename}' must be a string.")
            elif data["status"] not in STATUS_VALUES:
                invalid_status_filenames.append(filename)

        if "featured" in data and data["featured"] is not None:
            if not isinstance(data["featured"], str):
                malformed_errors.append(f"Featured for '{filename}' must be a string.")

    # 2. Filesystem vs Metadata alignment
    scanned_filenames = {p.name for p in scanned_files}

    # Notebook page exists -> Metadata missing
    for file_path in scanned_files:
        if file_path.name not in metadata_filenames:
            # Report the path relative to ROOT_DIRECTORY
            rel_path = file_path.relative_to(journals_dir).as_posix()
            missing_metadata.append(rel_path)

    # Metadata exists -> Notebook page missing
    for filename in metadata_filenames:
        if filename not in scanned_filenames:
            metadata_without_file.append(filename)

    return malformed_errors, missing_metadata, metadata_without_file, invalid_status_filenames


def detect_renames(missing_metadata: List[str], metadata_without_file: List[str]) -> None:
    """
    Performs fuzzy matching to identify potential file renames.
    Compares missing metadata filenames with extra metadata filenames.
    """
    # missing_metadata contains paths relative to journals root, extract filename only
    fs_unmatched = {Path(p).name: p for p in missing_metadata}
    meta_unmatched = set(metadata_without_file)

    for meta_name in sorted(meta_unmatched):
        for fs_name in sorted(fs_unmatched.keys()):
            similarity = difflib.SequenceMatcher(None, meta_name, fs_name).ratio()
            if similarity >= SIMILARITY_THRESHOLD:
                print("Possible rename detected")
                print("Metadata:")
                print(meta_name)
                print("Filesystem:")
                print(fs_name)
                print(f"Similarity: {round(similarity * 100)}%")
                print("This is only a warning.")
                print()


def generate_markdown_table(
    headers: List[str],
    alignments: List[str],
    rows: List[List[str]]
) -> str:
    """
    Generates a standard GitHub-Flavored Markdown table.
    Calculates column widths dynamically and pads cells for clean,
    visually aligned output.
    """
    num_cols = len(headers)
    col_widths = [len(h) for h in headers]

    # Calculate maximum width of each column across all rows
    for row in rows:
        for j in range(num_cols):
            if j < len(row):
                col_widths[j] = max(col_widths[j], len(row[j]))

    # Ensure minimum width is at least 3 for valid markdown alignment formatting
    for j in range(num_cols):
        col_widths[j] = max(col_widths[j], 3)

    # Helper function to pad a string based on alignment
    def pad_cell(text: str, width: int, alignment: str) -> str:
        if alignment == ":---:":
            return text.center(width)
        elif alignment == "---:":
            return text.rjust(width)
        else:  # Left aligned (e.g. :---) or default
            return text.ljust(width)

    # 1. Build Header Row
    header_cells = [pad_cell(headers[j], col_widths[j], alignments[j]) for j in range(num_cols)]
    header_row = "| " + " | ".join(header_cells) + " |"

    # 2. Build Alignment Row
    align_cells = []
    for j in range(num_cols):
        align = alignments[j]
        width = col_widths[j]
        if align == ":---:":
            cell = ":" + "-" * (width - 2) + ":"
        elif align == "---:":
            cell = "-" * (width - 1) + ":"
        elif align == ":---":
            cell = ":" + "-" * (width - 1)
        else:
            cell = "-" * width
        align_cells.append(cell)
    align_row = "| " + " | ".join(align_cells) + " |"

    # 3. Build Data Rows
    data_rows = []
    for row in rows:
        row_cells = []
        for j in range(num_cols):
            val = row[j] if j < len(row) else ""
            cell = pad_cell(val, col_widths[j], alignments[j])
            row_cells.append(cell)
        data_rows.append("| " + " | ".join(row_cells) + " |")

    return "\n".join([header_row, align_row] + data_rows)


def build_readme_string(
    scanned_files: List[Path],
    metadata: Dict[str, Any],
    journals_dir: Path
) -> str:
    """
    Assembles the final README.md content from configuration constants
    and dynamically generated table rows, including featured and regular sections.
    """
    readme_lines = []

    # 1. Document Title
    readme_lines.append(f"# {README_TITLE}")
    readme_lines.append("")

    # 2. Introductory description paragraphs
    for para in README_INTRODUCTION:
        readme_lines.append(para)
        readme_lines.append("")

    # Calculate summary numbers
    num_total = len(scanned_files)
    num_featured = 0
    files_metadata = metadata.get("files", {})
    for file_path in scanned_files:
        file_meta = files_metadata.get(file_path.name, {})
        if file_meta and "featured" in file_meta and file_meta["featured"] is not None:
            num_featured += 1
    num_regular = num_total - num_featured

    # Choose and format the dynamic summary template
    if num_featured > 0 and GENERATE_FEATURED_SECTION:
        summary_text = README_SUMMARY_TEMPLATE.format(
            total=num_total,
            featured=num_featured,
            regular=num_regular
        )
    else:
        summary_text = README_SUMMARY_TEMPLATE_NO_FEATURED.format(
            total=num_total,
            featured=num_featured,
            regular=num_regular
        )

    readme_lines.append(summary_text)
    readme_lines.append("")

    # Separate featured and regular rows
    featured_rows = []
    regular_rows = []
    
    featured_idx = 1
    regular_idx = 1

    for file_path in scanned_files:
        filename = file_path.name
        file_meta = files_metadata.get(filename, {})

        is_featured = file_meta and "featured" in file_meta and file_meta["featured"] is not None

        # Relative paths and markdown links
        relative_path = file_path.relative_to(journals_dir).as_posix()
        page_link = f"[{filename}]({relative_path})"

        category = file_path.parent.relative_to(journals_dir).as_posix()
        category_formatted = f"`{category}`"

        if is_featured and GENERATE_FEATURED_SECTION:
            # Featured Notebook Pages table row
            s_no = str(featured_idx)
            featured_idx += 1
            reason = file_meta.get("featured")
            if reason is None or reason == "":
                reason = MISSING_VALUE
            # Status column: same metadata field and placeholder behavior as the main table
            status = file_meta.get("status")
            if status is None or status == "":
                status = MISSING_VALUE
            featured_rows.append([s_no, page_link, category_formatted, reason, status])
        else:
            # Regular Notebook Pages table row
            s_no = str(regular_idx)
            regular_idx += 1
            description = file_meta.get("description")
            if description is None or description == "":
                description = MISSING_VALUE
            status = file_meta.get("status")
            if status is None or status == "":
                status = MISSING_VALUE
            regular_rows.append([s_no, page_link, category_formatted, description, status])

    # 3. Featured Notebook Pages section (if enabled and non-empty)
    if GENERATE_FEATURED_SECTION and len(featured_rows) > 0:
        readme_lines.append(f"## {README_FEATURED_TITLE}")
        readme_lines.append("")
        for para in README_FEATURED_DESCRIPTION:
            readme_lines.append(para)
            readme_lines.append("")
        
        featured_table = generate_markdown_table(
            FEATURED_TABLE_HEADERS,
            FEATURED_TABLE_ALIGNMENT,
            featured_rows
        )
        readme_lines.append(featured_table)
        readme_lines.append("")

    # 4. Notebook Pages section
    readme_lines.append(f"## {README_TABLE_TITLE}")
    readme_lines.append("")

    regular_table = generate_markdown_table(
        TABLE_HEADERS,
        TABLE_ALIGNMENT,
        regular_rows
    )
    readme_lines.append(regular_table)
    readme_lines.append("")

    # 5. Callout note
    readme_lines.append("> [!Note]")
    for para in README_NOTE:
        readme_lines.append(f"> {para}")

    # Return complete string with a trailing newline
    return "\n".join(readme_lines) + "\n"


def main() -> None:
    # Resolve directories and paths
    journals_dir = resolve_path(ROOT_DIRECTORY)
    metadata_path = journals_dir / METADATA_FILENAME
    readme_path = journals_dir / README_FILENAME

    # 1. Check directories existence
    if not journals_dir.is_dir():
        print(f"ERROR: Root directory does not exist: {journals_dir}", file=sys.stderr)
        sys.exit(1)

    # 2. Parse YAML metadata
    if not metadata_path.is_file():
        print(f"ERROR: Metadata file not found: {metadata_path}", file=sys.stderr)
        sys.exit(1)

    try:
        with open(metadata_path, "r", encoding="utf-8") as f:
            metadata = yaml.safe_load(f)
    except yaml.YAMLError as ye:
        print("ERROR\n", file=sys.stderr)
        print(f"Invalid YAML\n{ye}", file=sys.stderr)
        print("\nREADME was NOT generated.", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print("ERROR\n", file=sys.stderr)
        print(f"Could not read metadata file:\n{e}", file=sys.stderr)
        print("\nREADME was NOT generated.", file=sys.stderr)
        sys.exit(1)

    # 3. Recursively scan the directory for notebook pages
    scanned_files = scan_directory(journals_dir, SUPPORTED_EXTENSIONS)

    # 4. Validate metadata and files compatibility
    malformed_errors, missing_metadata, metadata_without_file, invalid_status_filenames = validate_metadata(
        metadata, scanned_files, journals_dir
    )

    # 5. Check duplicate filenames in filesystem
    filename_paths: Dict[str, List[Path]] = {}
    for path in scanned_files:
        filename_paths.setdefault(path.name, []).append(path)

    duplicate_errors = []
    for filename, paths in filename_paths.items():
        if len(paths) > 1:
            paths_str = "\n".join(p.relative_to(journals_dir).as_posix() for p in paths)
            duplicate_errors.append(f"{filename}\nPaths:\n{paths_str}")

    # Gather validation issues
    has_errors = bool(
        malformed_errors or
        missing_metadata or
        metadata_without_file or
        invalid_status_filenames or
        duplicate_errors
    )

    if has_errors:
        # Print detected warnings/renames first (if any)
        detect_renames(missing_metadata, metadata_without_file)

        # Print all errors formatted nicely
        error_blocks = []

        if malformed_errors:
            error_blocks.append("Malformed metadata\n" + "\n".join(malformed_errors))

        if duplicate_errors:
            error_blocks.append("Duplicate filenames\n" + "\n".join(duplicate_errors))

        if missing_metadata:
            error_blocks.append("Missing metadata\n" + "\n".join(missing_metadata))

        if metadata_without_file:
            error_blocks.append("Metadata without file\n" + "\n".join(metadata_without_file))

        if invalid_status_filenames:
            for fn in invalid_status_filenames:
                status_val = metadata["files"][fn].get("status", "")
                error_blocks.append(
                    f"Invalid status\n{fn}\n(value: {status_val})\nAllowed values\n" + "\n".join(STATUS_VALUES)
                )

        print("ERROR\n")
        print("\n--------------------------------\n".join(error_blocks))
        print("\nREADME was NOT generated.")
        sys.exit(1)

    # 6. Print warnings / possible renames if metadata and filesystem match but there are unmatched ones
    # (Though if validation succeeded, there are no unmatched entries, so this won't run, but good to have)
    detect_renames(missing_metadata, metadata_without_file)

    # 7. Generate README file
    readme_content = build_readme_string(scanned_files, metadata, journals_dir)

    try:
        with open(readme_path, "w", encoding="utf-8", newline="\n") as f:
            f.write(readme_content)
    except Exception as e:
        print(f"ERROR: Failed to write {readme_path}: {e}", file=sys.stderr)
        sys.exit(1)

    # Print success messages
    print("✓ Notebook pages discovered")
    print("✓ Metadata validated")
    print("✓ README generated")
    print("Done.")


if __name__ == "__main__":
    main()