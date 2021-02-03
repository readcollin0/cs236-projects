//
// Created by collin on 1/30/21.
//

#ifndef UNTITLED_AUTOMATONUNDEFINED_H
#define UNTITLED_AUTOMATONUNDEFINED_H

#include "Automaton.h"

class AutomatonUndefined : public Automaton {
private:
    int linesCount;
public:
    AutomatonUndefined() : Automaton(TokenType::UNDEFINED) {}


    int Start(const std::string& input) override {
        linesCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesCount;
    }

private:

    int s0(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return s1(input, pos + 1);
            case 0: if (input[pos] == '\'')
                    return s5(input, pos + 1);
                return 0;
            case -1: return 0;
        }
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, '|') == 1)
            return s2(input, pos + 1);
        return s4(input, pos); // Do not digest any characters.
    }

    int s2(const std::string& input, int pos) {
        switch (checkChar(input, pos, '|')) {
            case 1: return s3(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return pos;
        }
        return -1;
    }

    int s3(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return pos + 1;
            case 0: checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return pos;
        }
        return -1;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, '\n') == 0) // If it *did* find a character, but not \n
            return s4(input, pos + 1);
        return pos;
    }

    int s5(const std::string& input, int pos) {
        int state = checkChar(input, pos, '\'');
        switch (state) {
            case -1: return pos;
            case 1: return s6(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s5(input, pos + 1);
        }
        return -1; // SOMETHING BROKE, MAN.
    }

    int s6(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s5(input, pos + 1);
        return 0;
    }

    void checkNewLine(char c) {
        if (c == '\n') linesCount++;
    }
};

#endif //UNTITLED_AUTOMATONUNDEFINED_H
