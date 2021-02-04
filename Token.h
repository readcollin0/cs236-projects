//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H

#include <string>
#include <iostream>
#include "TokenType.h"

struct Token {
    TokenType type;
    std::string str;
    int lineNum;

    Token(TokenType type, std::string str, int lineNum)
            : type(type), str(str), lineNum(lineNum) {}
};

std::ostream& operator<<(std::ostream& out, const Token& token);


#endif //UNTITLED_TOKEN_H
