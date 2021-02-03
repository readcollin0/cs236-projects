//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONCOLONDASH_H
#define UNTITLED_AUTOMATONCOLONDASH_H

#include "Automaton.h"

class AutomatonColonDash : public Automaton {
public:
    AutomatonColonDash() : Automaton(TokenType::COLON_DASH) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, ':') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, '-') == 1)
            return pos + 1;
        return 0;
    }
};

#endif //UNTITLED_AUTOMATONCOLONDASH_H
