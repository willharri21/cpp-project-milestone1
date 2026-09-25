# 🥊 Project BallKnowledge

A console-based reference system for fighting game tips, tricks, terminology, and frame data — built to scale across as many games and characters as I can add over time, from ArcSys and Capcom to SNK, Aether Studios, NRS, and beyond.

## What It Does

Pick from the main menu to browse a game's roster for character frame data and cheese strategies, look up general fighting-game terminology in the Glossary, or check out FGC community slang. With multiple games loaded, you pick a game first, then choose to browse its characters or its cheese strategies.

## How to Run

1. Open `dev/main.cpp` in Visual Studio (or compile directly with `g++ dev/*.cpp -o app`)
2. Build and run
3. Choose an option from the main menu: Browse Games, View Glossary, or View FGC Slang

## Project Structure

- `dev/Move.h` — struct for a single move's frame data and notes
- `dev/Character.h` / `dev/Character.cpp` — a character and their moveset
- `dev/CheeseStrategy.h` — struct for an exploitable strategy tied to a game
- `dev/Game.h` / `dev/Game.cpp` — a game, its roster of characters, and its cheese strategies
- `dev/GlossaryTerm.h` — struct for a single technical glossary term
- `dev/Glossary.h` / `dev/Glossary.cpp` — collection of technical fighting-game terminology
- `dev/SlangTerm.h` — struct for a single FGC slang/culture term
- `dev/Slang.h` / `dev/Slang.cpp` — collection of FGC community slang, separate from technical Glossary terms
- `dev/main.cpp` — builds all loaded games/glossary/slang data, runs every menu, and holds the shared `getValidatedInt()` input validation function
- `docs/` — course documentation and assignment write-ups

## Currently Loaded

**Rivals of Aether 2** (Aether Studios) — full 17-character roster
- Verified move data: Ranno, Clairen, Zetterburn
- Roster only (moves not yet added): Fleet, Forsburn, Kragg, Loxodont, Maypul, Orcane, Wrastor, Etalus, Olympia, Absa, Galvan, La Reina, Slade, Gouie
- 2 Cheese Strategies

**Guilty Gear Strive** (Arc System Works) — 9 characters
- Verified move data: Sol Badguy
- Roster only (moves not yet added): Ky Kiske, May, Potemkin, Chipp Zanuff, Faust, Millia Rage, Giovanna, I-No
- 2 Cheese Strategies

**Glossary** — 10 technical terms: Wavedash, Whiff Punish, Floorhugging, IASA, Tiltboost, DACUS, Meaty, Okizeme, Frame Trap, Blockstring

**FGC Slang** — 8 community terms: GG, Salty, Bodied, Scrub, Footsies, Yomi, Rage Quit, Ganked

## Known Limitations / Honest Notes

Most roster entries beyond the original 4 characters don't have verified frame data yet — rather than invent numbers, those characters are listed with accurate names and archetypes and an empty moveset. This is intentional: accurate incompleteness over fabricated precision.

## Future Ideas (Beyond This Course)

- Fill in verified move data for the rest of both rosters
- A search feature across moves, glossary terms, and slang
- Additional games beyond Rivals of Aether 2 and Guilty Gear Strive
- Consolidating the four "browse a list, view detail" menu functions (Characters, Cheese Strategies, Glossary, Slang) into one shared function, the same way input validation was consolidated

⚠️ Frame data is community-sourced and tied to specific game patches — always worth double-checking against current patch notes before treating it as exact.

<br>

## 📢 Weekly Stand Up

### Week 2

⚙️ **Overview** – Started Project BallKnowledge this week — a console-based reference system for fighting game frame data, terminology, and strategy tips. Built the core class structure (`Move`, `Character`, `Game`) with real starter data for two Rivals of Aether 2 characters, then added a `GlossaryTerm`/`Glossary` system with a top-level menu so users can browse characters or look up general terminology.

🌵 **Challenges** – While testing, I found a real bug in my menu-input validation: when `std::cin` fails to read a number, it automatically sets the variable to `0` as of C++11, which was silently matching my "Exit" condition and quitting the program on any bad input. Fixed it by resetting the choice to a non-zero sentinel value after catching a failed read.

🏆 **Accomplishments** – Practiced building a second, independent data hierarchy (Glossary) alongside my existing Game/Character/Move structure.

🔮 **Next Steps** – Add the "cheese strategies" section, expand the character roster and glossary term list, and build a basic search feature.

### Week 3

⚙️ **Overview** – Expanded the project significantly: added a third Rivals of Aether 2 character (Zetterburn), added an entirely second game (Guilty Gear Strive, with Sol Badguy), and added two new glossary terms. Refactored `main()` to hold a `vector<Game>` instead of a single game, with a new game-selection menu.

🌵 **Challenges** – Refactored input validation away from `cin >> choice` + `cin.fail()` entirely, rebuilding it around `std::getline` + `std::stoi` wrapped in `try/catch`. Found that `stoi` alone would silently accept input like `"3abc"` and return `3`, ignoring the rest — fixed by checking that the entire line is consumed as a valid number.

🏆 **Accomplishments** – Consolidated input validation into one shared `getValidatedInt()` function used by every menu loop instead of duplicating the logic.

🔮 **Next Steps** – Build the cheese strategies section, add search, keep expanding the roster and glossary.

### Week 4 — Final Wrap-Up

⚙️ **Overview** – Closed out the course by significantly filling out the project's breadth: completed the full 17-character Rivals of Aether 2 roster and expanded Guilty Gear Strive to 9 characters, got the Cheese Strategies system fully working with real entries for both games, expanded the Glossary to 10 terms, and added a brand new FGC Slang section as its own independent system, separate from the technical Glossary. Also ran the whole codebase through the strictest compiler warnings I've used all course (`-Wall -Wextra -Wpedantic -Wshadow -Wconversion`) as a final quality pass.

🌵 **Challenges** – That strict compile actually caught something real: my `Character` and `Game` constructors had parameter names identical to their member variables (`name`/`archetype`, `title`/`publisher`), which `-Wshadow` flagged as shadowing. Not a bug, but a legitimate readability issue — fixed by renaming the parameters. I also made a deliberate choice not to invent frame data for the many roster characters I added late in the project; they're listed accurately by name and archetype with empty movesets rather than fabricated numbers, since I'd rather the project be honestly incomplete than confidently wrong.

🏆 **Accomplishments** – Looking back at where this started — a single hardcoded Task Manager with one file — to a multi-game, multi-system reference tool with five independent but consistently-structured data systems (Games/Characters/Moves, Cheese Strategies, Glossary, Slang) feels like real growth. The habit that stuck with me most this course is refactoring: I extracted input validation into one shared function early, and by the time I added Cheese Strategies and Slang later, adding new menus required zero new validation code — that payoff was the clearest "aha" moment of the whole class.

💬 **Feedback** – Peer feedback throughout the course reinforced testing thoroughly instead of assuming code works because it compiles, which is exactly what caught the `stoi("3abc")` edge case and the constructor shadowing issue — both were things that technically "worked" but weren't actually correct or clean until I went looking for problems on purpose.

🔮 **Next Steps** – After this course, I want to keep filling in verified frame data for the rest of both rosters, add the search feature that's been on the backlog since Week 2, and finally consolidate the four near-identical browse-menu functions the same way I did for input validation. This project was built to be a long-term hobby tool, not just a class assignment, so this is a "see you later," not a "the end."
