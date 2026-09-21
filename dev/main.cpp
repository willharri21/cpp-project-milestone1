#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.h"
#include "Character.h"
#include "Move.h"
#include "Glossary.h"
#include "GlossaryTerm.h"

// Reads a full line and converts it to an int using stoi, wrapped in
// try/catch. Keeps re-prompting until the user enters a valid whole number.
int getValidatedInt(const std::string& prompt) {
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        try {
            size_t pos = 0;
            int value = std::stoi(line, &pos);

            if (pos != line.size()) {
                std::cout << "That's not a valid whole number. Try again.\n";
                continue;
            }

            return value;
        } catch (const std::invalid_argument&) {
            std::cout << "That's not a valid whole number. Try again.\n";
        } catch (const std::out_of_range&) {
            std::cout << "That number's too large. Try again.\n";
        }
    }
}

// Builds Rivals of Aether 2 with three starter characters.
// Frame data is approximate/community-sourced and should be re-verified
// against the current patch before treating it as exact.
Game buildRivalsOfAether2() {
    Game roa2("Rivals of Aether 2", "Aether Studios");

    Character ranno("Ranno", "Fast rushdown / poison zoner");
    ranno.addMove({ "Jab 1", "Attack", 6, 8, 6,
        "Very fast, low commitment. Cancels into Tilts or a Rapid Jab finisher. "
        "Weak to floorhugging, so it's best used on airborne or shielding opponents." });
    ranno.addMove({ "Back Air", "Aerial Attack (facing away)", 5, 20, 16,
        "Reliable spacing and kill tool with a wide active window. "
        "Interruptible around frame 37, so respect the recovery if it's blocked." });

    Character clairen("Clairen", "Disjointed swordsman");
    clairen.addMove({ "Forward Tilt", "Tilt Attack", 12, 15, 8,
        "Strong horizontal disjoint used to control space. "
        "Slower than Jab but keeps opponents out further; good anti-approach tool." });
    clairen.addMove({ "Neutral Special", "Special Attack", 10, 14, 12,
        "Plasma trail projectile-style move. Useful for zoning and setting up follow-ups "
        "at mid-range rather than as a raw punish tool." });

    Character zetterburn("Zetterburn", "Fast, combo-heavy \"spacie\"");
    zetterburn.addMove({ "Shine", "Down Special", 2, 4, 10,
        "Frame 2 startup covering his body, cancellable into a jump. The core of his "
        "shield pressure, combo game, and one of the fastest, most versatile options in the cast." });
    zetterburn.addMove({ "Up Strong", "Strong Attack (up)", 8, 11, 14,
        "Fast anti-air with strong kill power, similar to a traditional fighting-game uppercut. "
        "One of his most consistent finishers out of Shine combos." });

    roa2.addCharacter(ranno);
    roa2.addCharacter(clairen);
    roa2.addCharacter(zetterburn);

    return roa2;
}

// Builds Guilty Gear Strive with one starter character.
// Frame data sourced from community frame data resources; re-verify
// against current patch notes before treating it as exact.
Game buildGuiltyGearStrive() {
    Game ggst("Guilty Gear Strive", "Arc System Works");

    Character sol("Sol Badguy", "Aggressive rushdown brawler");
    sol.addMove({ "5K", "Kick (standing)", 5, 6, 10,
        "Fast 5-frame knee that hits twice and doesn't whiff on crouching opponents the "
        "way 5P can. Both hits are jump/dash cancelable, making it a strong combo starter." });
    sol.addMove({ "Sidewinder Ignited", "214H (Special)", 12, 14, 10,
        "Rising uppercut-style special, roughly -10 on block/hit at minimum height. "
        "Used to convert combos rather than as a safe pressure tool given the frame disadvantage." });

    ggst.addCharacter(sol);

    return ggst;
}

// Builds a starter glossary of general fighting game terms
Glossary buildGlossary() {
    Glossary glossary;

    glossary.addTerm({ "Wavedash",
        "A tech using a jump immediately cancelled into an airdodge into the ground, "
        "giving fast horizontal movement with very little landing lag.",
        "Used to close distance quickly while staying in a low-commitment, actionable state." });

    glossary.addTerm({ "Whiff Punish",
        "Attacking an opponent right after one of their moves misses, "
        "capitalizing on the recovery frames (endlag) they're stuck in.",
        "If an opponent throws a slow attack that misses, punishing it before they can act again." });

    glossary.addTerm({ "Floorhugging",
        "A defensive option where a grounded character takes reduced knockback "
        "from certain low-power hits, staying on the ground instead of being launched.",
        "Ranno's Jab can be floorhugged by grounded opponents, reducing its follow-up potential." });

    glossary.addTerm({ "IASA",
        "Short for 'Interruptible As Soon As' \u2014 the exact frame a character "
        "can act again after using a move, even if the move's animation is still playing.",
        "A move with IASA frame 37 means the character can act on frame 37 even if recovery visually continues." });

    glossary.addTerm({ "Tiltboost",
        "Cancelling the startup of a Jab with a directional input to slide into a Tilt attack, "
        "gaining extra forward distance compared to using the Tilt on its own.",
        "Jab-cancelling into Forward Tilt to close extra distance before the Tilt's hitbox comes out." });

    glossary.addTerm({ "DACUS",
        "Short for 'Dash Attack Cancelled Up Strong' \u2014 cancelling the first few frames of a "
        "Dash Attack into a grounded Up Strong, letting a fast-moving dash lead into a kill move.",
        "Dashing in and DACUS-ing into Up Strong to convert horizontal momentum into a kill confirm." });

    return glossary;
}

void runCharacterMenu(Game& game) {
    int choice = -1;

    while (choice != 0) {
        game.listCharacters();
        std::cout << "0. Back\n";

        choice = getValidatedInt("Choose a character to view their moves: ");

        if (choice == 0) {
            break;
        }

        Character* selected = game.getCharacter(choice - 1);
        if (selected == nullptr) {
            std::cout << "No character at that number. Try again.\n";
        } else {
            selected->listMoves();
        }
    }
}

void runGameMenu(std::vector<Game>& games) {
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n--- Games ---\n";
        for (size_t i = 0; i < games.size(); ++i) {
            std::cout << (i + 1) << ". " << games[i].getTitle() << "\n";
        }
        std::cout << "0. Back to main menu\n";

        choice = getValidatedInt("Choose a game to browse: ");

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > static_cast<int>(games.size())) {
            std::cout << "No game at that number. Try again.\n";
        } else {
            runCharacterMenu(games[choice - 1]);
        }
    }
}

void runGlossaryMenu(Glossary& glossary) {
    int choice = -1;

    while (choice != 0) {
        glossary.listTerms();
        std::cout << "0. Back to main menu\n";

        choice = getValidatedInt("Choose a term to view its definition: ");

        if (choice == 0) {
            break;
        }

        glossary.showDefinition(choice - 1);
    }
}

int main() {
    std::vector<Game> games;
    games.push_back(buildRivalsOfAether2());
    games.push_back(buildGuiltyGearStrive());

    Glossary glossary = buildGlossary();
    int choice = -1;

    std::cout << "=== Project BallKnowledge ===\n";
    std::cout << "Fighting Game Tips, Tricks & Frame Data Reference\n";

    while (choice != 0) {
        std::cout << "\n1. Browse Games (" << games.size() << " loaded)\n";
        std::cout << "2. View Glossary\n";
        std::cout << "0. Exit\n";

        choice = getValidatedInt("Choose an option: ");

        if (choice == 1) {
            runGameMenu(games);
        } else if (choice == 2) {
            runGlossaryMenu(glossary);
        } else if (choice != 0) {
            std::cout << "Invalid option, try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
