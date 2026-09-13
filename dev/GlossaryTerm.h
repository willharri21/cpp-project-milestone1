#ifndef GLOSSARY_TERM_H
#define GLOSSARY_TERM_H

#include <string>

// Represents a single fighting game term/definition, not tied to
// any specific game or character
struct GlossaryTerm {
    std::string term;       // e.g. "Wavedash"
    std::string definition; // plain-language explanation
    std::string example;    // short example of the term in use
};

#endif
