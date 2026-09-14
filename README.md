# 🥊 Project BallKnowledge

A console-based reference system for fighting game tips, tricks, terminology, and frame data — built to scale across as many games and characters as I can add over time, from ArcSys and Capcom to SNK, Aether Studios, NRS, and beyond.

## What It Does

Pick from the main menu to either browse a game's roster for character frame data, or look up general fighting-game terminology in the glossary — all from the console.

## How to Run

1. Open `dev/main.cpp` in Visual Studio (or compile directly with `g++ dev/main.cpp dev/Character.cpp dev/Game.cpp dev/Glossary.cpp -o app`)
2. Build and run
3. Choose an option from the main menu: Browse Characters or View Glossary

## Project Structure

- `dev/Move.h` — struct for a single move's frame data and notes
- `dev/Character.h` / `dev/Character.cpp` — a character and their moveset
- `dev/Game.h` / `dev/Game.cpp` — a game and its roster of characters
- `dev/GlossaryTerm.h` — struct for a single glossary term, definition, and example
- `dev/Glossary.h` / `dev/Glossary.cpp` — collection of general fighting-game terminology
- `dev/main.cpp` — builds the current game/character/glossary data and runs the menus
- `docs/` — course documentation and assignment write-ups

## Currently Loaded

**Rivals of Aether 2** (Aether Studios)
- Ranno — Jab 1, Back Air
- Clairen — Forward Tilt, Neutral Special

**Glossary** — 4 starter terms: Wavedash, Whiff Punish, Floorhugging, IASA

## Planned Expansion

- More characters and moves per game
- Additional games (Guilty Gear, Street Fighter, King of Fighters, etc.)
- A "cheese strategies" section for mode-specific tips and shortcuts
- A search feature to look up moves/terms by keyword instead of only browsing menus

⚠️ Frame data is community-sourced and tied to specific game patches — always worth double-checking against current patch notes before treating it as exact.

<br>

## 📢 Weekly Stand Up

### Week 2

⚙️ **Overview** – Started a new project this week, Project BallKnowledge — a console-based reference system for fighting game frame data, terminology, and strategy tips. Built the core class structure (`Move`, `Character`, `Game`) with real starter data for two Rivals of Aether 2 characters, then added a `GlossaryTerm`/`Glossary` system with a top-level menu so users can browse characters or look up general terminology.

🌵 **Challenges** – While testing, I found a real bug in my menu-input validation: when `std::cin` fails to read a number, it automatically sets the variable to `0` as of C++11, which was silently matching my "Exit" condition and quitting the program on any bad input. Fixed it by resetting the choice to a non-zero sentinel value after catching a failed read.

🏆 **Accomplishments** – Practiced building a second, independent data hierarchy (Glossary) alongside my existing Game/Character/Move structure, and got direct experience with a subtle C++11 behavior change around failed stream extraction that I hadn't run into before.

🔮 **Next Steps** – Add the "cheese strategies" section, expand the character roster and glossary term list, and build a basic search feature across moves and glossary terms.
