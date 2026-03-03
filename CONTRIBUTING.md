# Contributing to RepX
Thank you for your interest in contributing to **RepX**.

RepX is a structured, append-only reputation engine built in C++ with a terminal-based UI. Its design emphasizes integrity, accountability, and architectural discipline. Before contributing, please understand the philosophy behind the system.


## 📌 Core Philosophy
RepX follows a strict **append-only ledger model** :

- Reputation entries are never edited.
- Every entry must include reasoning.
- History must remain traceable.
- Structural integrity is more important than feature speed.

Contributions must preserve this philosophy. If a change weakens traceability, ledger integrity, or architectural clarity, it will not be accepted.


## 🧱 Project Architecture
RepX follows a layered structure :
```
src/  
├── core/ -> Engine logic & configuration  
├── app/ -> UI behavior (layout, renderer, navigation, state)  
├── modules/ -> Reusable utilities  
└── packages/ -> Bundled third-party dependencies  
```
To understand the whole project structure in one go, follow [STRUCTURE](/STRUCTURE.md).

### Responsibilities
- **core/**  
  Maintains system invariants and configuration.
- **app/**  
  Handles layout computation, rendering flow, and navigation logic.
- **modules/**  
  Contains isolated utilities without engine ownership.

When contributing :
- Do not blur layer responsibilities.
- Do not mix UI logic with engine logic.
- Avoid circular dependencies.
- Avoid introducing hidden global state.


## 🧠 What to Contribute
We welcome :
- Architectural improvements
- Performance optimizations
- Clear bug fixes
- Internal consistency improvements
- Documentation refinements
- Structural refactors (with reasoning)

Avoid :
- Cosmetic changes without purpose
- Large unstructured feature dumps
- Changes that violate append-only design
- Introducing external dependencies without discussion

If a change involves architectural reasoning that cannot be fully conveyed through a commit message, record that thinking in [dev-logs](/docs/dev-logs.md). Dev logs capture intent - what changed, why it was necessary, and its expected impact. This is not required for every change, but it is strongly encouraged.


## 📝 Dev Logs
RepX maintains `docs/dev-logs.md`. This file is an internal engineering journal.

When contributing meaningful structural changes :
- Log your entry.
- Include concise bullet points.
- `Reason` is mandatory.
- `Impact` is optional.
- Keep it human-readable and short.

Dev logs capture **thinking**, not commit history.


## 📦 Commit Style
RepX follows the **Conventional Commits** format.

### Correct format :
```
<type(scope)>: <short_description> <optional_explanation>
```

### Example :
```
feat(layout): isolate layout computation from renderer
Isolated the layout computation from renderer.cpp as it was redundant. It now strengthens computation-first rendering pipeline.
```

### Common Types :
- `feat`, `fix`, `refactor`, `chore`, `docs`, `style`, `test`, `revert`, `build`, `ci`, `perf`

Avoid vague commits like :
- `update`
- `changes`
- `fixed stuff`

If unsure about commit classification, ask before merging.


## 🔍 Pull Requests
A good PR should :
- Clearly explain what changed.
- Explain why it changed.
- Mention architectural impact (if applicable).
- Stay focused on a single concern.

Large structural changes should be discussed before implementation.


## 📚 Documentation
When modifying public interfaces :

- Update documentation accordingly.
- Keep explanations clear and practical.
- Avoid unnecessary verbosity.
- Maintain formatting consistency.


## 🛡️ Integrity Rules
RepX enforces :
- Append-only reputation logic.
- Mandatory reasoning for entries.
- Transparent ledger generation.
- No silent mutation of historical data.

All contributions must respect these constraints.


## 💬 When in Doubt
Open an issue before making large changes.  
Architecture first. Code second.

> Thank you for helping build RepX. 🙏