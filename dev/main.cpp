#include <iostream>
#include <string>
#include <stdexcept>
#include "Game.h"
#include "Character.h"
#include "Move.h"
#include "Glossary.h"
#include "GlossaryTerm.h"

// Reads a full line and converts it to an int using stoi, wrapped in
// try/catch. Keeps re-prompting until the user enters a valid whole number.
// Replaces the old cin.fail()-based validation used in every menu.
int getValidatedInt(const std::string& prompt) {
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        try {
            size_t pos = 0;
            int value = std::stoi(line, &pos);

            // Make sure the ENTIRE line was consumed as the number,
            // so input like "3abc" doesn't silently become 3.
            if (pos != line.size()) {
                std::cout << "That's not a valid whole number. Try again.\n";
                continue;
            }

            return value;
        } catch (const std::invalid_argument&) {
            // No conversion could be performed (e.g. "abc", empty input)
            std::cout << "That's not a valid whole number. Try again.\n";
        } catch (const std::out_of_range&) {
            // Number is too large/small to fit in an int
            std::cout << "That number's too large. Try again.\n";
        }
    }
}

// Builds Rivals of Aether 2 with a couple of starter characters and moves.
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

    roa2.addCharacter(ranno);
    roa2.addCharacter(clairen);

    return roa2;
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

    return glossary;
}

void runCharacterMenu(Game& game) {
    int choice = -1;

    while (choice != 0) {
        game.listCharacters();
        std::cout << "0. Back to main menu\n";

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
    Game roa2 = buildRivalsOfAether2();
    Glossary glossary = buildGlossary();
    int choice = -1;

    std::cout << "=== Project BallKnowledge ===\n";
    std::cout << "Fighting Game Tips, Tricks & Frame Data Reference\n";

    while (choice != 0) {
        std::cout << "\n1. Browse Characters (" << roa2.getTitle() << ")\n";
        std::cout << "2. View Glossary\n";
        std::cout << "0. Exit\n";

        choice = getValidatedInt("Choose an option: ");

        if (choice == 1) {
            runCharacterMenu(roa2);
        } else if (choice == 2) {
            runGlossaryMenu(glossary);
        } else if (choice != 0) {
            std::cout << "Invalid option, try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
