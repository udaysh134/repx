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