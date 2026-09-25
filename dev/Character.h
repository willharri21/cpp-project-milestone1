#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Move.h"

class Character {
public:
    Character(const std::string& characterName, const std::string& characterArchetype);
    void addMove(const Move& move);
    void listMoves() const;
    const std::string& getName() const;

private:
    std::string name;
    std::string archetype;
    std::vector<Move> moves;
};

#endif
