# Milestone 4 Changelog — Project BallKnowledge

## Final Features Added
- Completed the full **Rivals of Aether 2** roster — all 17 current characters, up from the original 3
- Expanded the **Guilty Gear Strive** roster to 9 characters, up from the original 1
- Implemented a working **Cheese Strategies** system: new `CheeseStrategy` struct, storage and menu access through `Game`, with 2 real entries per game
- Expanded the **Glossary** from 4 to 10 technical terms (added Tiltboost, DACUS, Meaty, Okizeme, Frame Trap, Blockstring)
- Added a brand new **FGC Slang** section — a fully independent system (`SlangTerm`/`Slang`) for community culture terms (GG, Salty, Bodied, Scrub, Footsies, Yomi, Rage Quit, Ganked), kept separate from the technical Glossary
- Reworked the main menu into a 3-tier structure: main menu → game selection → per-game submenu (Browse Characters / View Cheese Strategies)

## Refactoring Improvements
- Replaced all `cin >> choice` + `cin.fail()` input handling with a single shared `getValidatedInt()` function using `std::getline` + `std::stoi` wrapped in `try/catch`. Used by every menu in the program (7+ call sites), with zero duplicated validation logic anywhere.
- Fixed a subtle correctness issue in that same refactor: `std::stoi` alone will silently accept input like `"3abc"` and return `3`, ignoring the trailing garbage. Added a check against the `pos` output parameter to require the *entire* input line be a valid number before accepting it.
- Renamed constructor parameters in `Character` and `Game` (`name`/`archetype`, `title`/`publisher`) after a strict compile with `-Wshadow` flagged them as shadowing their own member variables. Not a functional bug, but a real readability fix.

## Bug Fixes and Usability Updates
- Fixed a genuine logic bug from earlier in development: a failed `cin` read automatically sets the target variable to `0` under C++11, which was silently matching the "Exit" condition in every menu loop and quitting the program on any bad input. Resolved as part of the `stoi`-based rewrite, which doesn't rely on `cin`'s fail state at all.
- Hardened `getValidatedInt()` against an infinite loop if the input stream ever ends unexpectedly (e.g. redirected/empty input) rather than a user simply typing something invalid.
- Verified the full program compiles with zero warnings under `-Wall -Wextra -Wpedantic -Wshadow -Wconversion` — the strictest warning set used all course.

## Honest Notes on Scope
Roster characters added late in development (14 for Rivals of Aether 2, 8 for Guilty Gear Strive) have accurate names and archetypes but no move/frame data yet. Rather than invent frame numbers I couldn't verify, these are intentionally left as accurate placeholders. This is documented as a known limitation in the README rather than presented as complete.
