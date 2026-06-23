## 🌳 Repository Tree

This document outlines the high-level structure of RepX.
The project follows a layered architecture separating engine logic, application behavior, and reusable modules.
```
|   .gitignore
|   CHANGELOG.md
|   CONTRIBUTING.md
|   LICENSE
|   Makefile
|   README.md
|   STRUCTURE.md
|   
+---docs
|   |   dev-logs.md
|   |   
|   +---flowcharts
|   |       App_Engine_v1.png
|   |       App_Layout_v1.png
|   |       App_Renderer_Pipeline.png
|   |       
|   +---releases
|   |       INDEX.md
|   |       v0.1.0.md
|   |       v0.2.0.md
|   |       
|   \---workflow
|           page-systems.md
|           section-dividers.md
|           
+---packages
|   |   .gitkeep
|   |   
|   \---pdcurses
|       +---include
|       |       curses.h
|       |       panel.h
|       |       
|       \---lib
|               pdcurses.a
|               
+---prototype
|       canonicalStrings.jsonc
|       L_entrySchema.jsonc
|       L_stateSchema.jsonc
|       S_entrySchema.jsonc
|       S_stateSchema.jsonc
|       
+---snippets
|       pgTemp.code-snippets
|       secDiv.code-snippets
|       
\---src
    +---engine
    |   |   .gitignore
    |           
    +---interfaces
    |   +---cli
    |   |       .gitignore
    |   |       
    |   +---gui
    |   |       .gitignore
    |   |       
    |   \---tui
    |       |   main.cpp
    |       |   
    |       +---app
    |       |       layout.cpp
    |       |       layout.hpp
    |       |       navigation.cpp
    |       |       navigation.hpp
    |       |       renderer.cpp
    |       |       renderer.hpp
    |       |       state.cpp
    |       |       state.hpp
    |       |       
    |       +---core
    |       |   |   engine.cpp
    |       |   |   engine.hpp
    |       |   |   options.hpp
    |       |   |   registry.cpp
    |       |   |   registry.hpp
    |       |   |   
    |       |   \---reputation
    |       |           repEngine.hpp
    |       |           rep_inputOutput.cpp
    |       |           
    |       +---modules
    |       |       settings.cpp
    |       |       settings.hpp
    |       |       utils.cpp
    |       |       utils.hpp
    |       |       
    |       \---pages
    |               EXIT.cpp
    |               HOME.cpp
    |               NEW.cpp
    |               OPEN.cpp
    |               SETTINGS.cpp
    |               
    \---modes
        +---ledger
        |       .gitignore
        |       
        \---standard
                .gitignore
```

## 🔍 Overview

### /docs
Contains development logs, architectural flowcharts and workflow guides.

### /packages
Third-party packages or external libraries bundled locally.

### /snippets
Handy code snippets for easy use of recurring code blocks.

### /src
Primary source code directory, structurally split by interface/functionality.

- **engine/** - Code for the core engine logic (shared across interfaces).
- **modes/** - Mode-specific configuration and behavior (e.g., standard, ledger).
- **interfaces/** - User interface implementations.
    - **cli/** - Command line interface (CLI) logic.
    - **gui/** - Graphical user interface (GUI) logic.
    - **tui/** - Terminal user interface (TUI) logic.
        - **main.cpp** - Entry point of the TUI application.
        - **app/** - Application layer which handles layout, rendering, navigation, and state logic.
        - **core/** - Integral architectural layer which maintains engine, registry and system invariants.
        - **modules/** - Reusable utilities and global configurations that do not own engine logic.
        - **pages/** - Navigation pages for program's core navigation and visual interface + logic.