//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONQUERIES_H
#define UNTITLED_AUTOMATONQUERIES_H

#include "Automaton.h"

class AutomatonQueries : public Automaton {
public:
    AutomatonQueries() : Automaton(TokenType::QUERIES) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'Q') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'u') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 'r') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 'i') == 1)
            return s5(input, pos + 1);
        return 0;
    }

    int s5(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s6(input, pos + 1);
        return 0;
    }

    int s6(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};

#endif //UNTITLED_AUTOMATONQUERIES_H
