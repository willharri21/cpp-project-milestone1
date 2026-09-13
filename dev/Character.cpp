#include <iostream>
#include "Character.h"

Character::Character(const std::string& name, const std::string& archetype)
    : name(name), archetype(archetype) {
}

void Character::addMove(const Move& move) {
    moves.push_back(move);
}

const std::string& Character::getName() const {
    return name;
}

void Character::listMoves() const {
    std::cout << "\n=== " << name << " (" << archetype << ") ===\n";

    if (moves.empty()) {
        std::cout << "No moves logged yet.\n";
        return;
    }

    for (size_t i = 0; i < moves.size(); ++i) {
        const Move& m = moves[i];
        std::cout << (i + 1) << ". " << m.name << " [" << m.input << "]\n";
        std::cout << "   Startup: frame " << m.startupFrame
                   << " | Active until: " << m.activeEnd
                   << " | Endlag: " << m.endlagFrames << "f\n";
        std::cout << "   Notes: " << m.notes << "\n\n";
    }
}
