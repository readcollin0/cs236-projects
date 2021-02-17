//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H

#include <string>
#include <iostream>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    MY_EOF
};

const char* tokenTypeName(TokenType type);

struct Token {
    TokenType type;
    std::string str;
    int lineNum;

    Token(TokenType type, std::string str, int lineNum)
            : type(type), str(str), lineNum(lineNum) {}
};

std::ostream& operator<<(std::ostream& out, const Token& token);


#endif //UNTITLED_TOKEN_H
