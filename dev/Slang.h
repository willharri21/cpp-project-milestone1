#ifndef SLANG_H
#define SLANG_H

#include <string>
#include <vector>
#include "SlangTerm.h"

// Holds general FGC slang/culture terms, separate from the technical Glossary
class Slang {
public:
    void addTerm(const SlangTerm& term);
    void listTerms() const;
    void showMeaning(int index) const;

private:
    std::vector<SlangTerm> terms;
};

#endif
