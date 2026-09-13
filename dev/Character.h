#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Move.h"

// Represents a playable character and their moveset
class Character {
public:
    Character(const std::string& name, const std::string& archetype);

    void addMove(const Move& move);
    void listMoves() const;
    const std::string& getName() const;

private:
    std::string name;
    std::string archetype; // e.g. "Speedy zoner", "Disjoint-heavy swordsman"
    std::vector<Move> moves;
};

#endif
