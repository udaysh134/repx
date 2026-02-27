<div align="center">

# **RepX**
### Reputation as a Ledger

![Maintained](https://img.shields.io/badge/Maintained-Yes-green)
![Documentation Status](https://img.shields.io/badge/Documentation-Active-blue)

</div>

**RepX** is a lightweight reputation system built in C++ with a terminal-based navigation UI.

It records reputation through controlled, encrypted entries and generates transparent leaderboards from accumulated data. RepX follows a strict no-modification philosophy. Scores are never edited, every change is appended through structured logic, preserving a tamper-resistant history.

RepX ensures accountability, integrity, and trust by design - not by assumption.


<div align="center">

## 🧭 **The Problem & The Vision**
</div>

Most reputation systems focus on scoring. RepX focuses on accountability.

RepX treats reputation like a ledger. All of this data is encrypted and stored in a controlled `repboard.json`, accessible only through RepX.

<div align="center">

|    **Typical Reputation Systems**     |                **RepX**                 |
| :-----------------------------------: | :-------------------------------------: |
|        Scores can be modified         | Scores are never edited - only appended |
|         Reasons are optional          |   Reason is mandatory for every entry   |
|          History is unclear           |    Every entry records who and when     |
| Reputers operate without traceability |     Reputers are fully accountable      |
|       Bias is hard to challenge       |  Entries are verifiable and reviewable  |

</div>

Because every entry is traceable, the system enables :
- Validation of reputation claims.
- Publicly verifiable reasoning.
- Log generation from stored data.
- Robust structure to prevent silent manipulations.

> Trust is enforced by architecture - not authority.


<div align="center">

## 👥 **Who Is RepX For?**
</div>

RepX is built for any environment where reputation matters and accountability is important.

It can be used by :
- **Teachers** - tracking student performance or conduct
- **Employers** - evaluating employee contributions
- **Event hosts** - conducting competitive scoring systems
- **Community organizers** - running transparent leaderboards
- **Team leads** - monitoring developer productivity
- **Project maintainers** - managing open-source contributors

RepX is universal by design.
If someone can earn reputation, RepX can record it.


<div align="center">

## ✨ **Features**
</div>

### 🌐 Open Source :
- **Fully transparent and community-driven** - Find RepX repo in GitHub.
### 🛡️ Core Integrity :
- **Controlled Write Access Only** - Scores cannot be edited manually.
- **Tamper-Resistant History Linkage** - Every entry is permanently traceable.
- **Encrypted Reputation Data Storage** - Secure `repboard.json` file.
### 🕹️ Engine Design :
- **Lightweight C++ Executable** - No heavy runtime dependencies.
- **Portable Single Executable** - Manage reputation and generate leaderboards with one file.
- **Structured CLI Interaction** - Controlled, predictable command flow.
### 🧲 Usability :
- **Terminal-Based Navigation UI** - Keyboard-driven interface with structured navigation.
- **Automatic Leaderboard Generation** - Convert accumulated data into clean leaderboard output.


<div align="center">

## ⚖️ **Why RepX?**
</div>

Reputation can be tracked in many ways - spreadsheets, Discord bots, LMS systems, HR tools, etc.
But most of them are built for convenience, not integrity.

<div align="center">

| **Others**                  | **RepX**                         |
| :-------------------------: | :------------------------------: |
| Manual score editing        | No direct modification allowed   |
| Optional or missing reasons | Mandatory reason for every entry |
| Weak or no history tracking | Structured, traceable history    |
| Central authority control   | Transparent, verifiable entries  |
| Cloud/platform dependency   | Portable single executable       |
| Closed-source systems       | Fully open-source                |

</div>

RepX prioritizes structure over flexibility and accountability over convenience.

> It is not designed to be flashy. It is designed to be reliable.


<div align="center">

## ⚙️ **How It Works?**
</div>
 
RepX follows a controlled reputation flow.

```
User Input  
    ↓  
RepX Engine  
    ↓  
Encrypted repboard.json  
    ↓  
Leaderboard Generation  
    ↓  
leaderboard.md
```

<div align="center">

*Below is the most basic navigation flow of the application -*
    <table>
        <tr>
            <td>
                <img src="docs/flowcharts/App_Layout_v1.png" width="800"/>
            </td>
        </tr>
    </table>
</div>


<div align="center">

## 💻 **Developer Section**
</div>

RepX is built as a modular, engine-style system - not as a monolithic script. The architecture emphasizes :
- Clear separation between core and modules
- Explicit state management
- Controlled global configuration
- Compile-time invariants where possible
- Minimal external dependencies

RepX avoids unnecessary abstraction and hidden state.
Every component has a defined responsibility.

```
src/  
├── core/  
│ ├── engine  
│ └── settings  
│  
├── app/  
│ ├── layout  
│ ├── navigation  
│ ├── options  
│ ├── renderer  
│ └── state
│ 
├── modules/
│ └── utils
```

To view the whole project structure, follow [STRUCTURE](/STRUCTURE.md).

### 🪴 Design Principles :
- No silent mutations
- No accidental globals
- No direct score modification
- Architecture over convenience
- Structure over shortcuts

RepX treats reputation as infrastructure - not a feature.

### 🤝 Contribution :
Before contributing, understand that RepX prioritizes structure, integrity, and architectural clarity over rapid feature addition.

1. Fork the repository
2. Create a new branch for your feature or fix
3. Follow existing architectural patterns
4. Keep changes modular and intentional
5. Submit a pull request with a clear description


<div align="center">

## 📜 **License**
</div>

RepX is open-source software. It is distributed under the terms specified in the [LICENSE](/LICENSE) file of this repository.

You are free to use, modify, and distribute RepX in accordance with those terms. By keeping RepX open, the system remains transparent, auditable, and community-driven - aligned with its core philosophy of accountability and trust.
