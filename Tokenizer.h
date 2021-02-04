//
// Created by collin on 2/3/21.
//

#ifndef UNTITLED_TOKENIZER_H
#define UNTITLED_TOKENIZER_H

#include <string>
#include <vector>
#include "AutomataAll.h"

class Tokenizer {
private:
    std::vector<Automaton*> automata;

    void setupAutomata();
    void cleanUpAutomata();
public:
    Tokenizer() {
        setupAutomata();
    }

    ~Tokenizer() {
        cleanUpAutomata();
    }

    std::vector<Token> parseFile(std::string file);
};


#endif //UNTITLED_TOKENIZER_H
