# 🥊 Project BallKnowledge

A console-based reference system for fighting game tips, tricks, terminology, and frame data — built to scale across as many games and characters as I can add over time, from ArcSys and Capcom to SNK, Aether Studios, NRS, and beyond.

## What It Does

Pick from the main menu to browse a game's roster for character frame data, or look up general fighting-game terminology in the glossary — all from the console. With multiple games now loaded, you pick a game first, then a character within it.

## How to Run

1. Open `dev/main.cpp` in Visual Studio (or compile directly with `g++ dev/main.cpp dev/Character.cpp dev/Game.cpp dev/Glossary.cpp -o app`)
2. Build and run
3. Choose an option from the main menu: Browse Games or View Glossary

## Project Structure

- `dev/Move.h` — struct for a single move's frame data and notes
- `dev/Character.h` / `dev/Character.cpp` — a character and their moveset
- `dev/Game.h` / `dev/Game.cpp` — a game and its roster of characters
- `dev/GlossaryTerm.h` — struct for a single glossary term, definition, and example
- `dev/Glossary.h` / `dev/Glossary.cpp` — collection of general fighting-game terminology
- `dev/main.cpp` — builds all loaded games/glossary data, runs the menus, and holds the shared `getValidatedInt()` input validation function
- `docs/` — course documentation and assignment write-ups

## Currently Loaded

**Rivals of Aether 2** (Aether Studios)
- Ranno — Jab 1, Back Air
- Clairen — Forward Tilt, Neutral Special
- Zetterburn — Shine, Up Strong

**Guilty Gear Strive** (Arc System Works)
- Sol Badguy — 5K, Sidewinder Ignited

**Glossary** — 6 terms: Wavedash, Whiff Punish, Floorhugging, IASA, Tiltboost, DACUS

## Planned Expansion

- More characters and moves per game
- Additional games beyond Rivals of Aether 2 and Guilty Gear Strive
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

### Week 3

⚙️ **Overview** – Expanded Project BallKnowledge significantly this week. Added a third Rivals of Aether 2 character (Zetterburn), added an entirely second game (Guilty Gear Strive, with Sol Badguy as its first character), and added two new glossary terms (Tiltboost and DACUS). I also refactored `main()` to hold a `vector<Game>` instead of a single game, with a new `runGameMenu()` that lets the user pick which game to browse before picking a character.

🌵 **Challenges** – The biggest challenge was refactoring my input validation. I moved away from the old `cin >> choice` + `cin.fail()` approach entirely and rebuilt it around `std::getline` + `std::stoi` wrapped in `try/catch`, catching `std::invalid_argument` and `std::out_of_range`. While testing it, I found that `stoi` alone would silently accept input like `"3abc"` and just return `3`, ignoring the rest — so I added a check to make sure the entire line is consumed as a valid number, not just the beginning of it.

🏆 **Accomplishments** – Successfully consolidated input validation into one shared `getValidatedInt()` function used by all four menu loops instead of duplicating the logic, which is the refactor I planned last week. Adding the new game-selection menu didn't require writing any new validation code at all — just another call to the existing function, which is exactly the payoff refactoring is supposed to give you.

🔮 **Next Steps** – Build the "cheese strategies" section, add a basic search feature across moves and glossary terms, and keep expanding the roster and glossary further.
