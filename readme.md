# 🎮 48 Hours Before Dawn

A **terminal-based detective mystery game** written entirely in **C (C99)**. You investigate the murder of the Prime Minister of Varuna under strict time pressure. Forty-eight in-game hours. One correct accusation. Miss the truth, and the conspiracy survives.

---

## 🧠 Core Concept

This game is not about reflexes. It is about **reasoning under constraint**.

You must:

* Investigate locations
* Collect and connect evidence
* Interrogate suspects strategically
* Manage limited time
* Identify a political conspiracy, not just a killer

Every action costs time. Every mistake compounds.

---

## 📖 Story Premise

The Prime Minister of Varuna is found dead in his private study. Official cause: cardiac arrest.

Reality: murder.

Four suspects. Each with motive, access, and secrets. Surveillance gaps, altered medical records, and political maneuvering point toward something larger than a lone crime.

You have **48 hours** before the media leaks the story and chaos erupts.

---

## 🕹️ Gameplay Features

* ⏳ **Time-based pressure system** — every action consumes hours
* 🧾 **Evidence-driven progression** — evidence unlocks dialogue and contradictions
* 🧑‍⚖️ **Suspect interrogation** — four suspects with branching responses
* 🧠 **Logical win conditions** — accusation requires proof, not guesses
* 💾 **Save / Load system** — binary serialization, no checkpoints
* 🖥️ **Terminal UI** — ANSI rendering with typewriter-style text
* 🏁 **Multiple endings** — outcomes depend on reasoning quality

---

## 🏆 Endings

* **True Resolution** ⭐⭐⭐ — conspiracy exposed, justice served
* **Partial Truth** ⭐⭐ — one conspirator caught, others escape
* **False Accusation** ⭐ — wrong suspect, career destroyed
* **Media Leak** ☠️ — time runs out, truth buried

---

## 🚀 Quick Start

```bash
# Navigate to project directory
cd crime_scene

# Compile
make

# Run
./crime_scene_
      or
run
```

Controls:

* **SPACE** — continue narrative text
* **1–9** — select menu options
* **ENTER** — confirm choice

---

## 🛠️ Installation & Build Options

### Play Immediately (Precompiled)

```bash
cd crime_scene
./crime_scene_
```

### Clean Build

```bash
make clean
make
./crime_scene
```

### Debug Build

```bash
make debug
gdb ./crime_scene_
```

---

## 🧩 How to Win (No Spoilers)

To reach **True Resolution**, you must:

* Collect all critical evidence
* Identify the full conspiracy (not just the executor)
* Accuse the correct mastermind
* Have sufficient proof before accusing

Premature accusations are punished.

---

## 📂 Project Structure

```text
crime_scene/
├── evidence/              # Evidence tracking
├── locations/             # Location visits
├── save/                  # Binary save/load system
├── story/                 # Narrative scenes
├── suspects/              # Suspect system
├── ui/                    # Terminal rendering
├── utils/                 # Helper utilities
├── game.c / game.h        # Core game state
├── main.c                 # Game loop and menu
├── .gitignore             # Unnecessary Files
├── LICENSE                # License
├── Makefile               # Build system
├── Readme.md              # Project Info
```

---

## ⚙️ Technical Details

* **Language**: C (C99)
* **Architecture**: State machine
* **Evidence System**: Bitmask flags
* **Memory**: Static allocation only
* **Dependencies**: Standard C / POSIX only
* **Runtime Memory**: < 1 MB
* **Compiled Size**: ~39 KB

No external libraries. Fully portable across Linux and macOS.

---

## 🧪 Testing Scenarios

* Full clean build
* Save → exit → load validation
* Correct accusation with full evidence
* Wrong accusation paths
* Time-out (media leak)

---

## 📜 License

Free to use and modify for **educational purposes**.

---

> Power does not fear enemies. It fears daylight.

The clock is ticking.
