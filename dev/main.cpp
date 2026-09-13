#include <iostream>
#include "Game.h"
#include "Character.h"
#include "Move.h"

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

int main() {
    Game roa2 = buildRivalsOfAether2();
    int choice = -1;

    std::cout << "=== Project BallKnowledge ===\n";
    std::cout << "Fighting Game Tips, Tricks & Frame Data Reference\n";

    while (choice != 0) {
        roa2.listCharacters();
        std::cout << "0. Exit\n";
        std::cout << "Choose a character to view their moves: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "That's not a valid number. Try again.\n";
            continue;
        }

        if (choice == 0) {
            break;
        }

        Character* selected = roa2.getCharacter(choice - 1);
        if (selected == nullptr) {
            std::cout << "No character at that number. Try again.\n";
        } else {
            selected->listMoves();
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
