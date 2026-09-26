#ifndef CHEESE_STRATEGY_H
#define CHEESE_STRATEGY_H

#include <string>

// Represents an exploitable strategy or shortcut tied to a specific game,
// as opposed to raw per-move frame data
struct CheeseStrategy {
    std::string title;
    std::string description;
};

#endif
