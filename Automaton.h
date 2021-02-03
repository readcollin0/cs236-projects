//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATON_H
#define UNTITLED_AUTOMATON_H

#include <string>
#include "Token.h"

class Automaton {
protected:
    int read;
    TokenType tokenType;
public:
    Automaton(TokenType type) {
        tokenType = type;
    }

    virtual ~Automaton() {}

    virtual int Start(const std::string& input) = 0;

    virtual Token CreateToken(const std::string& input, int lineNum) {
        return Token(tokenType, input, lineNum);
    }

    TokenType getTokenType() {
        return tokenType;
    }

    virtual int linesRead() {
        return 0;
    }

protected:
    static bool charIn(char c, const char* str) {
        while (*str != 0) {
            if (*str == c)
                return true;
            str++;
        }
        return false;
    }

    static int checkChar(const std::string& str, size_t pos, char check) {
        if (str.length() <= pos)
            return -1;
        if (str.at(pos) == check)
            return 1;
        return 0;
    }

    static int checkStr(const std::string& str, size_t pos, const char* check) {
        if (str.length() >= pos)
            return -1;
        if (charIn(str.at(pos), check))
            return 1;
        return 0;
    }
};


#endif //UNTITLED_AUTOMATON_H
