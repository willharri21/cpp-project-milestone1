#ifndef MOVE_H
#define MOVE_H

#include <string>

// Represents a single move's frame data and notes
struct Move {
    std::string name;        // e.g. "Jab 1", "Back Air"
    std::string input;       // e.g. "A", "Forward + Aerial Attack"
    int startupFrame;        // frame the hitbox becomes active
    int activeEnd;           // last active frame
    int endlagFrames;        // recovery after the move ends
    std::string notes;       // usage tips, matchup notes, etc.
};

#endif
