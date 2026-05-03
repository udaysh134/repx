# 🧭 Page Systems
Pages represent the individual navigation screens of the program. Each page defines its own context, options, and logic, and registers itself with the navigation system. To maintain consistency across the project, all pages must follow the same location rules, naming conventions, and structural template.

## 📚 Table of Contents
- [📂 Page Location](/docs/workflow/page-systems.md#-page-location)
    - [📄 1. Directly inside pages](/docs/workflow/page-systems.md#1-directly-inside-pages)
    - [📁 2. Inside a single featured folder](/docs/workflow/page-systems.md#2-inside-a-single-featured-folder)
- [🧩 Page ID Registration](/docs/workflow/page-systems.md#-page-id-registration)
- [🆔 Option ID System](/docs/workflow/page-systems.md#-option-id-system)
    - [🧷 1. Definition](/docs/workflow/page-systems.md#-1-definition)
    - [🏗️ 2. Naming Convention for Containers](/docs/workflow/page-systems.md#️-2-naming-convention-for-containers)
    - [🔤 3. Naming Convention for ID String](/docs/workflow/page-systems.md#-3-naming-convention-for-id-string)
    - [🔁 4. Usage Flow](/docs/workflow/page-systems.md#-4-usage-flow)
- [🏷️ Page Naming Convention](/docs/workflow/page-systems.md#️-page-naming-convention)
- [🧱 Page File Structure](/docs/workflow/page-systems.md#-page-file-structure)
- [🔍 Template Explanation](/docs/workflow/page-systems.md#-template-explanation)
    - [📄 1. File Documentation](/docs/workflow/page-systems.md#-1-file-documentation)
    - [📦 2. Headers](/docs/workflow/page-systems.md#-2-headers)
    - [🧾 3. Definitions](/docs/workflow/page-systems.md#-3-definitions)
    - [🪧 4. Context](/docs/workflow/page-systems.md#-4-context)
    - [📋 5. Options](/docs/workflow/page-systems.md#-5-options)
    - [⚙️ 6. Logic Handlers](/docs/workflow/page-systems.md#️-6-logic-handlers)
    - [🛠️ 7. Helper Functions](/docs/workflow/page-systems.md#️-7-helper-functions)
    - [🧩 8. Page Configuration](/docs/workflow/page-systems.md#-8-page-configuration)
    - [🔗 9. Page Registration](/docs/workflow/page-systems.md#-9-page-registration)
- [📏 Consistency Rules](/docs/workflow/page-systems.md#-consistency-rules)
- [⚡ Editor Snippets](/docs/workflow/page-systems.md#-editor-snippets)


## 📂 Page Location
All page implementations must be placed inside `src/pages/`.

Pages may exist in two possible layouts :
### 📄 1. Directly inside pages
Used for standalone pages that are not part of a specific feature group.
```
# Example

src/pages/HOME.cpp
src/pages/SETTINGS.cpp
src/pages/EXIT.cpp
```
### 📁 2. Inside a single featured folder
If multiple pages belong to the same feature, a subfolder may be created.
```
# Example

src/pages/entry/VIEW_ENTRIES.cpp
src/pages/entry/ENTRY_ADD.cpp

src/pages/leaderboard/GEN_LB.cpp
src/pages/leaderboard/GEN_LB_WEEKLY.cpp
src/pages/leaderboard/GEN_LB_MONTHLY.cpp
```
> [!NOTE]  
> Only **one level of subfolder** inside `src/pages/` is allowed. Deeper nesting (e.g., `src/pages/leaderboard/generator/...`) is not permitted to keep the structure simple and consistent.


## 🧩 Page ID Registration
Every page must be declared inside `src/app/navigation.hpp`, specifically in : `enum class PageId`.
```cpp
# Example

enum class PageId {
    HOME,
    SETTINGS,
    GEN_LB,
    ENTRY_ADD,
    ERR_PAGE
};
```
> [!Important]  
> This step is **mandatory** as the navigation system relies on these identifiers to link and manage pages.


## 🆔 Option ID System
Every option in the system must be assigned a unique Option ID, defined centrally inside `src/core/options.hpp`. This ensures that UI interactions are handled consistently across all pages and removes reliance on labels for identifying actions.

> [!Important]  
> Every new option must have a corresponding entry in the **OptionId** namespace before it is used inside any page.
### 🧷 1. Definition
All Option IDs are declared inside :
```cpp
namespace OptionId {
    inline constexpr std::string_view HOME_CREATE_NEW = "home-crt_new";
    inline constexpr std::string_view NEW_SELECT_DIRECTORY = "new-slct_dir";
    ...
}
```
To create a new ID, duplicate an existing line and update both the container name and string value.
### 🏗️ 2. Naming Convention for Containers
```cpp
# Format

PAGE_ACTION_NAME
```
```cpp
# Example

HOME_CREATE_NEW
OPEN_SELECT_FILE
SETTINGS_DYNAMIC_RESIZE
```
- Always use page name as the prefix
- Use UPPERCASE with underscores
- This prevents collisions and keeps IDs grouped by page
### 🔤 3. Naming Convention for ID String
```cpp
# Format

page-name + "-" + short_label
```
```cpp
# Example

home-crt_new
new-slct_dir
open-slct_file
settings-dynm_res
```
- Each variable maps to a compact string
- Page name → full word (`home`, `open`, `settings`)
- Label → shortened (3–4 characters per word)
- Words separated using `_` (underscore)
- Page and label separated using `-` (hyphen / dash)
- Remove vowels where possible (`folder → fldr`, `path → pth`)
- Keep readability over strict shortening
- Allow longer forms when necessary (`settings → stngs`)
### 🔁 4. Usage Flow
When creating a new page :
- Define required option IDs in `options.hpp`
- Use those IDs inside the page's `options` vector
- Implement logic using the assigned IDs

This establishes a consistent interaction pipeline across the system.


## 🏷️ Page Naming Convention
All pages follow some strict naming rules.
- **Uppercase Identifiers** : Every page name must be written in uppercase.  
Examples : `HOME`, `SETTINGS`, `EXIT`.

- **Use of Underscores** : When a page name contains multiple words, they must be separated using underscores and nothing else.  
Examples : `ERR_PAGE`, `ENTRY_ADD`, `GEN_LB`.

- **Matching of file Name** : The `.cpp` file name must match the identifier used in PageId, like this `PageId::GEN_LB` → `GEN_LB.cpp`.  
Examples : `HOME.cpp`, `ERR_PAGE.cpp`, `ENTRY_ADD.cpp`, `GEN_LB.cpp`

Even if this naming style may appear unusual, it ensures consistent mapping between navigation IDs and file implementations.


## 🧱 Page File Structure
Every page must follow the standard template below :
```cpp
/**
 * @file EXAMPLE_PAGE.cpp
 * @brief Page module for EXAMPLE_PAGE navigation page.
 */

// Headers
#include "registry.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"

// Definitions
using type = Options::Type;
using placement = Options::Placement;
using targetPage = Navigation::PageId;
using PageConfig = Registry::PageConfig;
using Page = Navigation::PageId;
using Registrar = Registry::PageRegistrar;


// ----------------------------------------------------------------------------------------------------
// Context
// ----------------------------------------------------------------------------------------------------

static Navigation::PageContext context {
    "example", // Path label
    "This is an example page!!" // Footer message (optional)
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    {
        "Option 1",
        OptionId::EXAMPLE_PAGE_OPTION_1,
        type::ACTION,
        placement::BODY,
        targetPage::PAGE_1
    },
    { 
        "Option 2",
        OptionId::EXAMPLE_PAGE_OPTION_2,
        type::INPUT,
        placement::BODY,
        targetPage::PAGE_2
    },
    { 
        "Option 3",
        OptionId::EXAMPLE_PAGE_OPTION_3,
        type::TEXT,
        placement::BODY,
        targetPage::PAGE_3
    },
    { 
        "Option 4",
        OptionId::EXAMPLE_PAGE_OPTION_4,
        type::SELECTION,
        placement::FOOTER,
        // No target page for this option
    },
};


// ----------------------------------------------------------------------------------------------------
// Logic
// ----------------------------------------------------------------------------------------------------

// On Enter ---------------------------------------- >>

static void onEnter(Navigation& nav, State& state) {
    // Optional page initialization logic
}

// On Action ---------------------------------------- >>

static void onAction(Navigation& nav, State& state, const Options::Item& item) {
    // Optional action logic after pressing ENTER on an ACTION item
}

// On Input ---------------------------------------- >>

static void onInput(Navigation& nav, State& state, int key) {
    // Optional key handling specific to this page
}


// ----------------------------------------------------------------------------------------------------
// Helper Functions (Optional)
// ----------------------------------------------------------------------------------------------------

// Helper Function 1 ---------------------------------------- >>

void helperFunction_1() {
    // logic for this function...
}

// Helper Function 2 ---------------------------------------- >>

int helperFunction_2() {
    // logic for this function...
}


// ----------------------------------------------------------------------------------------------------
// Page Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::EXAMPLE_PAGE,
    context,
    options,
    onEnter,
    onAction,
    onInput // "nullptr" if a specific handler is not required
};


// ----------------------------------------------------------------------------------------------------
// Page Registration
// ----------------------------------------------------------------------------------------------------

static Registrar reg(page);
```


## 🔍 Template Explanation
### 📄 1. File Documentation
Each page must include a Doxygen-style file comment at the top.
```cpp
/**
 * @file HOME.cpp
 * @brief Page module for HOME navigation page.
 */
 ```
Since page modules do not have corresponding header files, the file-level documentation is included directly in the `.cpp`.

Immediately after this documentation block, the file begins with the standard project structure, which includes section dividers to organize the code visually. Although section dividers are not documentation themselves, they are an important part of the project's readability and organization standards.

Section dividers help separate major areas of a page such as:
- Context
- Options
- Logic
- Helper Functions
- Page Configuration
- Page Registration

> [!Note]  
> For details about the divider system and how it should be used, refer to : [`section-dividers.md`](/docs/workflow/section-dividers.md)
### 📦 2. Headers
These headers are always required :
```cpp
#include "registry.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"
```
Additional headers may be included if necessary.  
When adding system headers, separate them from project headers with a blank line.
### 🧾 3. Definitions
The `using` aliases are part of the standard template and must not be modified.  
They simplify references to frequently used types and ensure consistency across all pages.
### 🪧 4. Context
```cpp
static Navigation::PageContext context
```
This defines metadata about the page.

- The label is used in the breadcrumb navigation path.
- The footer message is reserved for future use.
### 📋 5. Options
```cpp
static std::vector<Options::Item> options
```
Each entry defines a selectable option on the page.

- **Structure** : `{ label, optionId, type, placement, targetPage }`
- **Example** : 
```cpp
    {
        "Create New",
        OptionId::HOME_CREATE_NEW,
        type::ACTION,
        placement::BODY,
        targetPage::NEW
    },
    {
        "Open Existing",
        OptionId::HOME_OPEN_EXISTING,
        type::ACTION,
        placement::BODY,
        targetPage::OPEN
    }
```
These values come from [`options.hpp`](/src/core/options.hpp)
### ⚙️ 6. Logic Handlers
Three optional handlers are available for now :
```cpp
onEnter() { ... }

// Runs when the page becomes active.
// Used for initialization or state setup.
```
```cpp
onAction() { ... }

// Runs when the user presses ENTER on an ACTION option.
```
```cpp
onInput() { ... }

// Handles page-specific keyboard input.
```
> [!Note]  
> These handlers should be separated using Level 2 section dividers. If you are unfamiliar with section dividers, refer to : `docs/workflow/section-dividers.md`
### 🛠️ 7. Helper Functions
Optional functions used by page logic may be placed here.  
Each helper function should also be separated using Level 2 section dividers to maintain readability.
### 🧩 8. Page Configuration
This structure connects the page components together.
```cpp
static PageConfig page
```
```cpp
# Fields

- Page ID
- context
- options
- onEnter
- onAction
- onInput
```
The only value that typically changes here is the **Page ID**.

If any of the handlers (`onEnter`, `onAction`, or `onInput`) are not implemented, their place must be filled with a **null pointer (`nullptr`)** instead of a function name. The template already defaults these to `nullptr`, and contributors must maintain this behavior if handlers are unused.
### 🔗 9. Page Registration
```cpp
static Registrar reg(page);
```
This line registers the page automatically during program initialization.  
The `PageRegistrar` constructor calls an internal registration function that maps : `PageId` → `PageConfig`

This allows the engine to retrieve the correct page configuration at runtime. Without this line, the page will not be recognized by the navigation system.


## 📏 Consistency Rules
To maintain a consistent architecture across the project :
- Do not rename template variables such as `context`, `options`, or `page`.
- Do not remove mandatory sections.
- Always use the defined section dividers.
- Always follow the page naming convention.


## ⚡ Editor Snippets
A snippet is provided to quickly generate the page template.  
Snippet file : [`/snippets/pgTemp.code-snippets`](/snippets/pgTemp.code-snippets)

> Using this snippet allows contributors to insert the entire page structure instantly and focus only on implementing the page logic.