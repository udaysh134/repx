# Changelog
All notable changes to this project will be documented in this file.

This format is inspired by [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), but follows a custom hybrid structure designed specifically for RepX. Subtle emoji usage is intentional to improve readability and user experience, as this changelog serves both developers and end users.

This project adheres to Semantic Versioning.  
Go to [`INDEX.md`](/docs/releases/INDEX.md) to get the index of all the releases untill now, with quick navigations.

<!-- New release after this line -->
## 🧩 [RepX v0.2.0](https://github.com/udaysh134/repx/releases/tag/v0.2.0) - Architectural Expansion (Mar 12, 2026)

### 💡 Summary :
Version 0.2.0 significantly expands the internal architecture and contributor infrastructure of RepX. This release introduces automatic dynamic layout resizing, a new page registry and configuration system, and multiple improvements to the project's modular design.

Alongside architectural upgrades, the repository has undergone major documentation expansion, workflow improvements, and developer tooling enhancements to support long-term open-source collaboration and scalability.

### 🛠️ Changes :

#### [ - ] Added
- Automatic live dynamic resizing of the entire terminal layout, allowing header, body, footer, breadcrumbs, and UI components to adjust instantly to window size changes
- Page Registry system to provide structured page labeling and contextual navigation support
- Page handler lifecycle hooks allowing pages to manage their own logic during navigation events
- Modular page configuration system enabling self-contained page options, handlers, and context
- Self-registering page modules allowing pages to automatically register themselves without centralized engine updates
- Fallback handling for missing page registrations to prevent runtime crashes
- Cursor position preservation during navigation for improved user experience
- Comprehensive page system documentation for contributors
- VS Code snippet templates for creating new pages and maintaining consistent code structure
- Workflow documentation for section dividers and internal code organization standards
- Development log system to record architectural decisions, changes, and learning notes

#### [ - ] Changed
- Engine updated to support automatic real-time layout resizing without requiring manual input refresh
- Page registry architecture evolved through multiple stages, transitioning from simple page context labels to a full page configuration system
- Project structure reorganized to improve separation between core engine systems and modular components
- Utility modules moved into the core architecture to better reflect their foundational role
- Build system improved with recursive source discovery, removing the need to manually update the Makefile when adding new source files
- Documentation across the repository expanded and refined, including README, CONTRIBUTING, STRUCTURE, and developer workflow guides
- Inline documentation improved across core engine modules to align with the project's documentation standards

#### [ - ] Fixed
- Breadcrumb path labeling accuracy through the introduction of the page registry system

#### [ - ] Removed
- Centralized options management system, replaced by decentralized page-level option configuration

> [!Note]  
> A rendering artifact related to terminal resizing is currently known and documented, and will be addressed in a future architectural update.




## 🧩 [RepX v0.1.0](https://github.com/udaysh134/repx/releases/tag/v0.1.0) - Foundational Release (Mar 04, 2026)

### 💡 Summary :
Version 0.1.0 marks the first public foundation for RepX. This release establishes the core terminal engine and modular architecture of the project. It formalizes the transition from experimental structure to a scalable, state-driven rendering system that future versions of RepX will build upon.

### 🛠️ Changes :

#### [ - ] Added
- Core engine loop with modular structure
- State-based navigation system with breadcrumb flow
- Dedicated renderer and layout modules
- Centralized global configuration system
- UTF-8 console rendering support
- Rounded UI components with dynamic margin control
- Minimum screen-size validation interface
- Structured options system and menu flow
- Project documentation, contribution guidelines, and flowcharts

#### [ - ] Changed
- Refactored project into a clean, engine-driven architecture
- Restructured source tree for long-term scalability
- Reworked layout logic to align with centralized settings

#### [ - ] Removed
- Legacy experimental application structure
- PDCurses dependency (replaced with Windows API-based console handling)
- Redundant drawing utilities and duplicate namespaces