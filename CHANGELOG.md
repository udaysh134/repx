# Changelog
All notable changes to this project will be documented in this file.

This format is inspired by [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), but follows a custom hybrid structure designed specifically for RepX. Subtle emoji usage is intentional to improve readability and user experience, as this changelog serves both developers and end users.

This project adheres to Semantic Versioning.

---

<!-- New release after this line -->

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