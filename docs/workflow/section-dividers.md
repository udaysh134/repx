# 🧱 Section Dividers
This project uses a structured comment divider system to organize code into clearly readable sections. These dividers are not decorative, they exist to maintain visual hierarchy, readability, and consistency across the codebase.

All contributors should follow these patterns when structuring code. The divider system follows a four-level hierarchy, each serving a different purpose.

| **Level** |                               **Name**                               |     **Purpose**     | **Typical Use**                      |
|:---------:|:--------------------------------------------------------------------:|:-------------------:|:------------------------------------ |
|  Level 1  | [Major Divider](/docs/workflow/section-dividers.md#-1-major-divider) | Major file sections | Large structural boundaries          |
|  Level 2  | [Minor Divider](/docs/workflow/section-dividers.md#-2-minor-divider) |    Logic headers    | Steps inside algorithms or functions |
|  Level 3  | [Micro Divider](/docs/workflow/section-dividers.md#-3-micro-divider) |   Micro sections    | Small grouped state or variables     |
|  Level 4  |       [Comment](/docs/workflow/section-dividers.md#-4-comment)       |   Normal comments   | Notes and explanations               |

---

## 🟥 1. Major Divider
```
// ----------------------------------------------------------------------------------------------------
// Section Name
// ----------------------------------------------------------------------------------------------------
```
### Purpose :
This is the highest-level divider used in the project. It separates **major structural sections** within a file.
### Typical Usage :
- Defining a major class section in header files
- Separating constructors and method implementations
- Grouping public and private implementation areas
- Dividing major modules inside a `.cpp` file
### Guidelines :
- The divider must remain exactly the same length.
- Do not modify the number of dashes.
- Use clear and short section titles.
- Only use this divider for large structural boundaries.
### Example :
```
// ----------------------------------------------------------------------------------------------------
// Renderer
// ----------------------------------------------------------------------------------------------------

Renderer::Renderer() {
    ...
}
```


## 🟧 2. Minor Divider
```
// Section name ---------------------------------------- >>
```
### Purpose :
This divider acts as a sub-heading inside code and is used to break complex logic into readable steps. It helps large functions or algorithms remain easy to scan.
### Typical Usage :
- Separating stages of an algorithm
- Breaking layout or rendering calculations into steps
- Grouping related logic within functions
### Guidelines :
- Use short action-oriented titles
- Prefer Title Case
- Avoid very long descriptions
### Example :
```
// Validate Minimum Size ---------------------------------------- >>

if (width < minWidth) {
    ...
}

// Determine Usable Area ---------------------------------------- >>

int usableWidth = width - margin * 2;
```


## 🟨 3. Micro Divider
```
// -------- [ Section Name ]
```
### Purpose :
This divider is used for small grouped areas of code that need separation but do not require a full logic header. It is intentionally lighter than the Minor divider.
### Typical Usage :
- Grouping temporary variables
- Grouping state values
- Small internal sections inside functions
### Guidelines :
- Keep titles short (1–3 words)
- Use Title Case
- Avoid verbs when possible
### Example :
```
// -------- [ Cursor Cache ]

int cursorX = state.cursor.x;
int cursorY = state.cursor.y;

// -------- [ Frame State ]

bool isActive = renderer.active;
```


## 🟩 4. Comment
```
// Normal comment
```
### Purpose :
This is the standard comment used for explanations, notes, or quick clarifications.
### Typical Usage :
Normal comments can appear in two common forms :
1. *Inline comment* : Placed at the end of a code line.
2. *Standalone note* : Placed above the code it describes.
### Guidelines :
- Use for explanations or small notes
- Do not use this in place of structured dividers when separating logic
### Example :
```
# Inline

int width = 80; // Default terminal width


# Standalone

// Calculate body width
int bodyWidth = totalWidth - margin;
```


## 📏 General Rules
1. Use dividers intentionally. Avoid inserting them randomly.
2. Maintain the visual hierarchy :
    - Major Divider
    - Minor Divider
    - Micro Divider
    - Normal Comment
3. Keep titles short and meaningful.
4. Do not modify the divider styles or formatting.


## ⚡ Editor Snippets
To simplify inserting section dividers, VS Code snippets are provided in the repository.  
Snippet file : [`/snippets/secDiv.code-snippets`](/snippets/secDiv.code-snippets)

> [!Note]
> Using these snippets, contributors can quickly insert the correct divider format by typing a short prefix. Setup instructions for installing the `code-snippets` file locally (for **VS Code on Windows**) and using the snippet prefixes are documented inside the snippet file itself.