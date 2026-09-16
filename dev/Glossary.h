#ifndef GLOSSARY_H
#define GLOSSARY_H

#include <string>
#include <vector>
#include "GlossaryTerm.h"

// Holds a collection of general fighting-game terms and definitions
class Glossary {
public:
    void addTerm(const GlossaryTerm& term);
    void listTerms() const;
    void showDefinition(int index) const;
    int termCount() const;

private:
    std::vector<GlossaryTerm> terms;
};

#endif
