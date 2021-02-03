//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONID_H
#define UNTITLED_AUTOMATONID_H

#include "Automaton.h"

class AutomatonID : public Automaton {
public:
    AutomatonID() : Automaton(TokenType::ID) {}

    int Start(const std::string &input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, size_t pos) {
        if (input.length() <= pos) return 0;
        if (std::isalpha(input[pos]))
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, size_t pos) {
        if (input.length() > pos && isalnum(input[pos]))
            return s1(input, pos + 1);
        if (isReserved(input, pos))
            return 0;
        return pos;
    }

    bool isReserved(const std::string& input, int len) {
        if (len == 5) {
            return checkReserved(input, "Facts", len) || checkReserved(input, "Rules", len);
        } else if (len == 7) {
            return checkReserved(input, "Queries", len) || checkReserved(input, "Schemes", len);
        }
        return false;
    }

    bool checkReserved(const std::string& a, const std::string& reserved, int len) {
        return (a.substr(0, len) == reserved);
    }
};

#endif //UNTITLED_AUTOMATONID_H
