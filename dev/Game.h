#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Character.h"

// Represents a fighting game and its roster
class Game {
public:
    Game(const std::string& title, const std::string& publisher);

    void addCharacter(const Character& character);
    void listCharacters() const;
    Character* getCharacter(int index);
    int characterCount() const;
    const std::string& getTitle() const;

private:
    std::string title;
    std::string publisher;
    std::vector<Character> characters;
};

#endif
