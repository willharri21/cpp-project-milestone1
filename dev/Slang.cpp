#include <iostream>
#include "Slang.h"

void Slang::addTerm(const SlangTerm& term) {
    terms.push_back(term);
}

void Slang::listTerms() const {
    std::cout << "\n--- FGC Slang ---\n";
    if (terms.empty()) {
        std::cout << "No terms added yet.\n";
        return;
    }
    for (size_t i = 0; i < terms.size(); ++i) {
        std::cout << (i + 1) << ". " << terms[i].term << "\n";
    }
}

void Slang::showMeaning(int index) const {
    if (index < 0 || index >= static_cast<int>(terms.size())) {
        std::cout << "No term at that number.\n";
        return;
    }
    const SlangTerm& t = terms[index];
    std::cout << "\n" << t.term << "\n";
    std::cout << "Meaning: " << t.meaning << "\n";
    std::cout << "Example: " << t.example << "\n";
}
