//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONSTRING_H
#define UNTITLED_AUTOMATONSTRING_H

#include "Automaton.h"

class AutomatonString : public Automaton {
private:
    int linesReadCount;
public:
    AutomatonString() : Automaton(TokenType::STRING) {}

    int Start(const std::string& input) override {
        linesReadCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesReadCount;
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        int state = checkChar(input, pos, '\'');
        switch (state) {
            case -1: return 0;
            case 1: return s2(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s1(input, pos + 1);
        }
        return -1; // SOMETHING BROKE, MAN.
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s1(input, pos + 1);
        return pos;
    }

    void checkNewLine(char c) {
        if (c == '\n') linesReadCount++;
    }
};

#endif //UNTITLED_AUTOMATONSTRING_H
