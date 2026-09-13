# 🥊 Project BallKnowledge

A console-based reference system for fighting game tips, tricks, terminology, and frame data — built to scale across as many games and characters as I can add over time, from ArcSys and Capcom to SNK, Aether Studios, NRS, and beyond.

## What It Does

Pick a game, pick a character, and pull up their moves with startup/active/endlag frame data plus usage notes and matchup tips — all from the console.

## How to Run

1. Open `dev/main.cpp` in Visual Studio, or compile directly:
   `g++ dev/main.cpp dev/Character.cpp dev/Game.cpp -o app`
2. Build and run
3. Choose a character from the menu to view their frame data

## Project Structure

- `dev/Move.h` — struct for a single move's frame data and notes
- `dev/Character.h` / `dev/Character.cpp` — a character and their moveset
- `dev/Game.h` / `dev/Game.cpp` — a game and its roster of characters
- `dev/main.cpp` — builds the current game/character data and runs the menu
- `docs/` — course documentation and assignment write-ups

## Currently Loaded

**Rivals of Aether 2** (Aether Studios)
- Ranno — Jab 1, Back Air
- Clairen — Forward Tilt, Neutral Special

## Planned Expansion

- More characters and moves per game
- Additional games (Guilty Gear, Street Fighter, King of Fighters, etc.)
- A universal glossary system for fighting game lingo (meaty, oki, whiff punish, etc.)
- A "cheese strategies" section for mode-specific tips and shortcuts

⚠️ Frame data is community-sourced and tied to specific game patches — always worth double-checking against current patch notes before treating it as exact.
