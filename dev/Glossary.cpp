#include <iostream>
#include "Glossary.h"

void Glossary::addTerm(const GlossaryTerm& term) {
    terms.push_back(term);
}

int Glossary::termCount() const {
    return static_cast<int>(terms.size());
}

void Glossary::listTerms() const {
    std::cout << "\n--- Glossary ---\n";
    if (terms.empty()) {
        std::cout << "No terms added yet.\n";
        return;
    }

    for (size_t i = 0; i < terms.size(); ++i) {
        std::cout << (i + 1) << ". " << terms[i].term << "\n";
    }
}

void Glossary::showDefinition(int index) const {
    if (index < 0 || index >= static_cast<int>(terms.size())) {
        std::cout << "No term at that number.\n";
        return;
    }

    const GlossaryTerm& t = terms[index];
    std::cout << "\n" << t.term << "\n";
    std::cout << "Definition: " << t.definition << "\n";
    std::cout << "Example: " << t.example << "\n";
}
