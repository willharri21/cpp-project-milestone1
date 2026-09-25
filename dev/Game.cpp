#include <iostream>
#include "Game.h"

Game::Game(const std::string& gameTitle, const std::string& gamePublisher)
    : title(gameTitle), publisher(gamePublisher) {
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

void Game::addCheeseStrategy(const CheeseStrategy& strategy) {
    cheeseStrategies.push_back(strategy);
}

void Game::listCheeseStrategies() const {
    std::cout << "\n--- " << title << " Cheese Strategies ---\n";
    if (cheeseStrategies.empty()) {
        std::cout << "No cheese strategies added yet.\n";
        return;
    }
    for (size_t i = 0; i < cheeseStrategies.size(); ++i) {
        std::cout << (i + 1) << ". " << cheeseStrategies[i].title << "\n";
    }
}

void Game::showCheeseStrategy(int index) const {
    if (index < 0 || index >= static_cast<int>(cheeseStrategies.size())) {
        std::cout << "No strategy at that number.\n";
        return;
    }
    const CheeseStrategy& s = cheeseStrategies[index];
    std::cout << "\n" << s.title << "\n";
    std::cout << s.description << "\n";
}
