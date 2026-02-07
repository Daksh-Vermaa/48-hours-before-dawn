# 🎮 48 Hours Before Dawn

<div align="center">

[![Made with C](https://img.shields.io/badge/Made%20with-C%20(C99)-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![License](https://img.shields.io/badge/License-Educational%20Use-green?style=for-the-badge)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-blue?style=for-the-badge&logo=linux&logoColor=white)](https://github.com/Daksh-Vermaa/48-hours-before-dawn)
[![Build System](https://img.shields.io/badge/Build-Make-9C3D54?style=for-the-badge&logo=cmake&logoColor=white)](Makefile)
[![Code Size](https://img.shields.io/badge/Binary%20Size-~39%20KB-inactive?style=for-the-badge)

**A terminal-based detective mystery game** where every decision matters and time is your deadliest enemy.

[⬇️ Quick Start](#-quick-start) • [🎮 How to Play](#-how-to-play) • [📂 Project Structure](#-project-structure) • [🏆 Endings](#-endings)

</div>

---

## 🎯 About

Investigate the murder of Varuna's Prime Minister in **48 in-game hours**. Uncover a political conspiracy, interrogate suspects, connect evidence, and race against time. This isn't about reflexes—it's about **reasoning under pressure**.

**The clock is ticking. Every decision counts. One wrong accusation ends your career.**

---

## 🧠 Core Philosophy

```
┌─────────────────────────────────────────────┐
│  NOT a reflex-based action game             │
│  PURE logical deduction under time pressure │
│  Evidence-driven progression                │
│  Multiple branching outcomes                │
└─────────────────────────────────────────────┘
```

### Your Objectives

- 🔍 **Investigate** locations and collect evidence
- 📋 **Connect** clues to unlock dialogue options
- 👤 **Interrogate** suspects and detect contradictions
- ⏳ **Manage** your 48 hours strategically
- 🧩 **Expose** the conspiracy before time runs out

---

## 📖 The Story

<table>
<tr>
<td width="50%">

**The Crime:**
> The Prime Minister of Varuna is found dead in his private study.
> 
> Official cause: **Cardiac arrest**
> 
> Reality: **Murder**

</td>
<td width="50%">

**The Challenge:**
> 4 suspects with motive
> 
> Surveillance gaps
> 
> Altered medical records
> 
> Political maneuvering

</td>
</tr>
</table>

**You have 48 hours before the media leaks the story and chaos erupts.**

---

## 🕹️ Gameplay Features

| Feature | Description |
|---------|-------------|
| ⏳ **Time-Based Pressure** | Every action consumes in-game hours |
| 🧾 **Evidence-Driven** | Evidence unlocks dialogue and contradictions |
| 🧑‍⚖️ **Suspect System** | Four suspects with branching responses based on your evidence |
| 🧠 **Logical Win Conditions** | Accusations require proof, not guesses |
| 💾 **Save/Load System** | Binary serialization—exit anytime, resume later |
| 🖥️ **Terminal UI** | ANSI rendering with typewriter-style narrative text |
| 🏁 **Multiple Endings** | Outcomes depend entirely on your reasoning |

---

## 🏆 The Endings

Reach different conclusions based on your investigation:

```
⭐⭐⭐ TRUE RESOLUTION
    └─ Conspiracy fully exposed, justice served

⭐⭐ PARTIAL TRUTH
    └─ One conspirator caught, others escape

⭐ FALSE ACCUSATION
    └─ Wrong suspect, career destroyed

☠️ MEDIA LEAK
    └─ Time runs out, truth buried forever
```

---

## 🚀 Quick Start

### Prerequisites
- **GCC/Clang** compiler
- **Make** build tool
- **POSIX-compatible OS** (Linux, macOS)

### Clone & Run

```bash
# Clone the repository
git clone https://github.com/Daksh-Vermaa/48-hours-before-dawn.git
```

```bash
# Build and run 
make run
```

```bash
# Rebuild and Run
make clean
make run
```

### 🎮 Controls

| Control | Action |
|---------|--------|
| **SPACE** | Continue narrative text |
| **1–9** | Select menu options |
| **ENTER** | Confirm choice |

---

## 🧩 How to Win (No Spoilers)

To achieve **True Resolution** ⭐⭐⭐:

1. ✅ Collect **all critical evidence** from locations
2. ✅ **Identify the full conspiracy** (not just the executor)
3. ✅ **Accuse the mastermind** strategically
4. ✅ Have **sufficient proof** before accusing

⚠️ **Warning:** Premature accusations lock you into inferior endings.

---

## 📂 Project Architecture

```
crime_scene/
├── evidence/              # Evidence tracking system
├── locations/             # Location visit handlers
├── save/                  # Binary save/load system
├── story/                 # Narrative scenes & dialogue
├── suspects/              # Suspect interrogation logic
├── ui/                    # Terminal rendering & ANSI
├── utils/                 # Helper utilities
├── game.c / game.h        # Core game state machine
├── main.c                 # Game loop & menu system
├── .gitignore             # VCS ignore rules
├── LICENSE                # Educational license
├── Makefile               # Build configuration
└── README.md              # This file
```

---

## ⚙️ Technical Specifications

<table>
<tr>
<td>

**Language Stack**
- C (C99 Standard)
- Pure ANSI/POSIX
- Zero external dependencies

</td>
<td>

**Performance**
- Runtime Memory: **< 1 MB**
- Binary Size: **~39 KB**
- Fully portable
- State machine architecture

</td>
</tr>
<tr>
<td colspan="2">

**Core Systems**
- **Evidence:** Bitmask flag system for tracking
- **Memory:** Static allocation only (no heap fragmentation)
- **Architecture:** Event-driven state machine
- **Serialization:** Binary format for save/load

</td>
</tr>
</table>

---

## 🧪 Testing Checklist

- [x] Full clean build verification
- [x] Save → exit → load validation
- [x] Correct accusation with full evidence path
- [x] Wrong accusation branching paths
- [x] Time-out scenario (media leak ending)
- [x] All suspect dialogue trees
- [x] Cross-platform compilation (Linux/macOS)

---

## 💡 Tips for Players

> **Hint 1:** The obvious suspect isn't always guilty.
>
> **Hint 2:** Pay attention to contradictions between suspects' statements.
>
> **Hint 3:** Time management is crucial—plan your investigation route carefully.
>
> **Hint 4:** Re-interview suspects after collecting new evidence.

---

## 🤝 Contributing

Educational use and modifications are welcome. Feel free to:
- Fork and experiment
- Learn C and game architecture
- Submit improvements

---

## 📜 License

Free to use and modify for **educational purposes**.

See [LICENSE](LICENSE) for details.

---

## 📊 Project Stats

<div align="center">

![Language: C](https://img.shields.io/badge/Language-C%20(98.2%25)-A8B9CC?style=flat-square&logo=c)
![Build: Make](https://img.shields.io/badge/Build-Make%20(1.8%25)-9C3D54?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-POSIX%20Compliant-blue?style=flat-square)

**Developed with ❤️ as an educational project**

</div>

---

<div align="center">

> **"Power does not fear enemies. It fears daylight."**
>
> The clock is ticking. ⏳

**[Start Your Investigation](#-quick-start)**

</div>