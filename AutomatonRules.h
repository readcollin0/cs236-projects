//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONRULES_H
#define UNTITLED_AUTOMATONRULES_H

#include "Automaton.h"

class AutomatonRules : public Automaton {
public:
    AutomatonRules() : Automaton(TokenType::RULES) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'R') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'u') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'l') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};

#endif //UNTITLED_AUTOMATONRULES_H
