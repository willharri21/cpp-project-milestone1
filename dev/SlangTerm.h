#ifndef SLANG_TERM_H
#define SLANG_TERM_H

#include <string>

// Represents a piece of FGC (Fighting Game Community) slang/culture,
// separate from mechanical Glossary terms
struct SlangTerm {
    std::string term;
    std::string meaning;
    std::string example;
};

#endif
