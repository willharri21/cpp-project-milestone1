# Milestone 2 Planning Worksheet — Project BallKnowledge

## Project Overview

Project BallKnowledge is a console-based reference system for fighting game tips, tricks, terminology, and frame data. It currently supports one game (Rivals of Aether 2) with two characters (Ranno and Clairen), each with a couple of moves and their frame data.

## Step 1: Gather Inspiration

I looked at how existing fighting game frame data resources are structured — sites like Dragdown wiki organize data as Game → Character → Move, with each move showing startup, active frames, endlag, and written notes/strategy tips alongside the raw numbers. I also looked at how glossary-style resources (like a game's own in-game tips or community wikis) separate general terminology from character-specific data, since terms like "wavedash" or "whiff punish" apply across many characters and games at once rather than belonging to just one move.

The main thing I took away: keeping general concepts (glossary terms) separate from character-specific data (moves) makes a system much easier to expand later, since I won't need to duplicate definitions across every character that uses a term.

## Step 2: Plan Your Features

**New features I'm planning to add:**
- A **Glossary** system: a list of general fighting-game terms (e.g. wavedash, whiff punish, floorhugging, IASA) with definitions, separate from any one character
- A **Cheese Strategies** section: game/character-specific tips for exploitable strategies or shortcuts, tagged separately from raw frame data since it's more advice-driven
- Expanded roster: additional characters and additional moves per character within Rivals of Aether 2
- A basic **search** feature so a user can look up a term or move by keyword instead of only browsing by menu

**System behavior:**
- The main menu will grow from "pick a character" to a top-level menu offering: Browse Characters, View Glossary, View Cheese Strategies, Search
- Each of these will be its own function/loop, returning to the main menu when the user is done

**User interaction:**
- User picks a top-level option from the main menu
- For Browse Characters: same flow as now (pick character → view moves)
- For Glossary: list terms alphabetically, let user pick one to see the full definition
- For Search: user types a keyword, program checks move names, glossary terms, and cheese strategy titles for a match and displays results

**Program flow:**
- `main()` will call a new top-level menu function instead of jumping straight into character selection
- New `Glossary` class (holding a vector of `GlossaryTerm` structs) and a `CheeseStrategy` struct, following the same pattern as `Move`/`Character`/`Game`

## Step 3–4: Design Before You Build

**Breaking this into manageable pieces:**
1. Add `GlossaryTerm` struct + a simple `Glossary` class with `addTerm()` and `listTerms()`
2. Add `CheeseStrategy` struct + storage (likely a `vector<CheeseStrategy>` directly in `Game`, since strategies are usually game-specific)
3. Rework `main()` to show a top-level menu instead of jumping straight to characters
4. Add search functionality last, once the other data types exist to search through

**Class/system evolution:**
- `Move`, `Character`, and `Game` stay as they are — they're working correctly
- `GlossaryTerm` and `Glossary` are new, independent of the Game/Character/Move hierarchy
- `CheeseStrategy` is new and will likely live as a member of `Game`, since strategies are usually specific to one game rather than one character

## Step 5: Begin Implementation

Plan for this week: implement the Glossary system first (smallest, most self-contained piece), test it in isolation, then move on to Cheese Strategies, then rework the main menu to tie everything together. Search comes last since it depends on the other systems existing first.

## Not Sure What to Add? — Reflection

- **More useful:** the Glossary and Cheese Strategies sections directly extend the original vision for this project (tips beyond just raw frame data)
- **Easier to use:** a top-level menu and search feature make the tool easier to navigate as it grows beyond two characters
- **Feels incomplete right now:** frame data is currently hardcoded for only 2 characters/moves — expanding the roster is an ongoing task alongside these new features
