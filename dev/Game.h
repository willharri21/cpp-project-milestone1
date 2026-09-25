#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Character.h"
#include "CheeseStrategy.h"

class Game {
public:
    Game(const std::string& gameTitle, const std::string& gamePublisher);

    void addCharacter(const Character& character);
    void listCharacters() const;
    Character* getCharacter(int index);
    int characterCount() const;
    const std::string& getTitle() const;

    void addCheeseStrategy(const CheeseStrategy& strategy);
    void listCheeseStrategies() const;
    void showCheeseStrategy(int index) const;

private:
    std::string title;
    std::string publisher;
    std::vector<Character> characters;
    std::vector<CheeseStrategy> cheeseStrategies;
};

#endif
