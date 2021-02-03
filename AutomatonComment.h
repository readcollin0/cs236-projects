//
// Created by collin on 1/30/21.
//

#ifndef UNTITLED_AUTOMATONCOMMENT_H
#define UNTITLED_AUTOMATONCOMMENT_H

#include "Automaton.h"

class AutomatonComment : public Automaton {
private:
    int linesCount;
public:
    AutomatonComment() : Automaton(TokenType::COMMENT) {}

    int Start(const std::string& input) override {
        linesCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesCount;
    }

private:
    void checkNewLine(char c) {
        if (c == '\n') linesCount++;
    }

    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, '#') == 1)
            return s1(input, pos + 1);
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
            case -1: return 0;
        }
        return -1;
    }

    int s3(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return pos + 1;
            case 0:
                checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return 0;
        }
        return -1;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, '\n') == 0) // If it *did* find a character, but not \n
            return s4(input, pos + 1);
        return pos;
    }
};

#endif //UNTITLED_AUTOMATONCOMMENT_H
