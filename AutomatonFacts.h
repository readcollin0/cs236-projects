//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONFACTS_H
#define UNTITLED_AUTOMATONFACTS_H

#include "Automaton.h"

class AutomatonFacts : public Automaton {
public:
    AutomatonFacts() : Automaton(TokenType::FACTS) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'F') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'a') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'c') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 't') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};

#endif //UNTITLED_AUTOMATONFACTS_H
