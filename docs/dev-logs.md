<!--
===========================================================================
GUIDELINES
===========================================================================

This file serves as an internal engineering journal for RepX.
It captures developer thinking, reasoning, and architectural evolution.

It is NOT :
- A replacement for git commit history
- A replacement for CHANGELOG.md
- A strict rule-based reporting system

It IS :
- A structured space to record why decisions were made
- A historical record of how the system evolved
- A communication layer between developers


===========================================================================
RULES (Important)
===========================================================================

1. Insert new entries at the top (latest first).
2. Use the date format : "Mar 02, 2026 - Monday".
3. One section per developer per day.
4. Developer name must link to GitHub profile:
    - [Full Name](https://github.com/username)
5. Use bullet points for main log entries.
6. Keep entries concise (one-liners or short summaries).
7. Avoid logging trivial or cosmetic changes.
8. When writing `Reason` and `Impact` :
   - Write them on consecutive lines.
   - Add TWO trailing spaces at the end of the `Reason` line.
   - Do NOT insert a blank line between them.
   - This ensures proper line break without visual spacing gap.

    Correct format:

    `Reason` : Explanation here.··
    `Impact` : Explanation here.

    (The two dots above represent two trailing spaces.)
9. Never use backticks (`) for anything other than "Reason" & "Impact".

--------------------------------------------------

1. Reason is mandatory.
    - Every entry must explain WHY the change was made.
    - Code changes are visible in git - thinking is not.
2. Impact is optional.
    - If the change has architectural or structural consequences,
    - mention expected or observed impact.
3. Write naturally.
    - This is human-readable engineering journaling.
    - Avoid robotic phrasing or over-formality.
4. Do not over-explain.
    - Keep logs short, but meaningful.


===========================================================================
TEMPLATE (Example)
===========================================================================

## 🗞️ Mar 02, 2026 - Monday
#### [Dev_1](https://github.com/dev_1)
- Separated layout computation from renderer responsibilities.
- Removed implicit dimension recalculations inside render layer.

`Reason` : Renderer performing computation blurred module responsibility and weakened deterministic flow.  
`Impact` : Layout is now finalized before rendering begins, improving predictability and future scalability.

#### [Dev_2](https://github.com/dev_2)
- Introduced a centralized configuration struct inside core instead of passing scattered constants across modules.
- Removed hardcoded layout values from app layer.
- Decided not to introduce a third-party terminal abstraction library.
- Kept rendering dependent on native Windows console APIs.

`Reason` : Configuration was implicitly spreading across multiple files, which risked silent inconsistency as the system grows.


===========================================================================
IMPORTANT NOTES
===========================================================================

- Dev Logs begin after the release of v0.1.0, prior development is not recorded here.
- If there is no meaningful reasoning, it likely does not belong in this file.
- This file is for architectural memory - not activity tracking.
- Never modify or remove this guidelines section.
-->
## 🗞️ May 03, 2026 - Saturday
#### [Uday](https://github.com/udaysh134)
- Synced release documentation by linking docs/releases/INDEX.md and updating references in CHANGELOG and v0.2.0 notes.
- Set up initial reputation engine structure with Windows directory selection to establish base input flow.
- Added COM initialization in main and fixed current page resolution to stabilize navigation and file dialog usage.
- Introduced centralized option ID system to map UI options to consistent actions across all pages.
- Updated Makefile to support new modules and Windows COM dependencies.
- Added file selection support using Windows File Explorer with filtering for `.repx` workflows.
- Improved settings to support selector customization and configurable footer button spacing.
- Implemented dynamic footer system with context-based messages, wrapping, centering, overflow handling, and button priority.
- Fixed alignment issues by decoupling layout from selector/prefix width in both body and footer rendering.
- Added directional navigation: vertical for body (↑ ↓) and horizontal for footer (← →) with proper section transitions.

`Reason` : Focus shifted from static structure to making the system interaction-ready—connecting filesystem input, stabilizing navigation flow, and making UI behavior consistent across pages.  
`Impact` : RepX now has a working input pipeline for `.repx` data, a reliable action-mapping system via option IDs, and a much more stable and intuitive UI layout and navigation model.


## 🗞️ Mar 11, 2026 - Wednesday
#### [Uday](https://github.com/udaysh134)
- Replaced the centralized options.cpp model with a modular per-page configuration system.
- Refactored pages so each file owns its context, options, and logic.
- Implemented cursor preservation so selection state persists when returning to a page.
- Removed the centralized options declaration that previously restricted page modularity.
- Added docs/workflow/ to document contributor workflows and architectural patterns.
- Introduced a Section Divider guide describing the project's code-organization levels.
- Added VS Code snippets for divider templates to ensure consistent usage.
- Created a comprehensive Page System guide covering page IDs, structure, and conventions.
- Added page template snippets to simplify consistent page creation.
- Performed a repository-wide documentation pass for newly introduced systems.

`Reason` : The previous centralized option definition created tight coupling between page modules and a single configuration file, which reduced modularity and made page development unnecessarily rigid. By shifting to a self-contained page architecture, each page now owns its behavior, options, and context, enabling true modular expansion of the system. At the same time, extensive contributor documentation and snippet tooling were introduced to standardize development patterns and reduce onboarding friction.  
`Impact` : Page development is now decentralized and significantly easier to extend. New pages can be created as independent modules without modifying centralized configuration files, improving maintainability and scalability of the engine. Cursor preservation also improves navigation continuity, making the interface behave more like a polished application rather than a stateless menu system.


## 🗞️ Mar 10, 2026 - Tuesday
#### [Uday](https://github.com/udaysh134)
- Debugged the initialization issue discovered the previous day while working on the Page Registry system.
- Identified the root cause as a Static Initialization Order Fiasco, where some page modules attempted to access the global context map before it had been constructed.
- Confirmed the behavior while isolating the issue by temporarily removing the modules folder during debugging.
- Adjusted the initialization flow so registry and context structures exist before any page registration occurs.
- Finally completely resolved the earlier issue where breadcrumbs rendered as empty path segments ("/ / /") due to missing context data.

`Impact` : Navigation is now cleanly structured and self-descriptive. Each page registers itself with the registry, which manages its context. The engine can now resolve page transitions and breadcrumb paths reliably through a single centralized system, significantly simplifying navigation flow and improving maintainability.  
`Learning` : 
- **Static Initialization Order Fiasco** - understood how global objects across translation units can initialize in unpredictable order.
- **Function Pointers** - learned how functions can be referenced and invoked through stored addresses.
- **Lambda Functions** - explored how lambdas can attach lightweight handlers to systems like the page registry.


## 🗞️ Mar 09, 2026 - Monday
#### [Uday](https://github.com/udaysh134)
- Introduced a **Page Registry System** to centralize page registration, navigation handling, and breadcrumb context resolution across the engine.
- Replaced the earlier implicit context requirement (which defaulted to an empty context in *engine.cpp*) with a structured registry that maps page IDs → context metadata.
- Implemented automatic breadcrumb generation by attaching navigation context directly to each registered page, ensuring correct path labels during runtime navigation.

`Reason` : The previous navigation model expected every page to provide contextual information but lacked a structured system to enforce or manage it. As a result, the engine defaulted to empty context objects, causing breadcrumb labels to render as blank segments during navigation. The Page Registry introduces a single loader-like handler that registers pages before program start and supplies the required context to the navigation system.


## 🗞️ Mar 08, 2026 - Sunday
#### [Uday](https://github.com/udaysh134)
- Implemented dynamic resizing for the main rendering frame and overall application layout.
- Made "*clrScreen()*" static to enable Windows buffer-level screen clearing to be used internally across modules.

`Reason` : The interface needed to adapt to changing terminal dimensions to maintain a GUI-like experience. Without dynamic adjustment, the fixed layout makes it obvious that the program is operating on a character-based row-and-column terminal grid.  
`Impact` : The application now automatically recalculates and adjusts the entire layout based on the available screen space during runtime. Due to the way the Windows screen buffer operates, this can leave behind residual artifacts outside the visible frame. The active viewport continues to render correctly, but scrolling may reveal these underlying buffer remnants.
