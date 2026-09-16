#include <iostream>
#include "Game.h"

Game::Game(const std::string& title, const std::string& publisher)
    : title(title), publisher(publisher) {
}

void Game::addCharacter(const Character& character) {
    characters.push_back(character);
}

const std::string& Game::getTitle() const {
    return title;
}

int Game::characterCount() const {
    return static_cast<int>(characters.size());
}

Character* Game::getCharacter(int index) {
    if (index < 0 || index >= static_cast<int>(characters.size())) {
        return nullptr;
    }
    return &characters[index];
}

void Game::listCharacters() const {
    std::cout << "\n--- " << title << " (" << publisher << ") Roster ---\n";
    for (size_t i = 0; i < characters.size(); ++i) {
        std::cout << (i + 1) << ". " << characters[i].getName() << "\n";
    }
}
