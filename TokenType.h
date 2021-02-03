//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_TOKENTYPE_H
#define UNTITLED_TOKENTYPE_H

#include <string>

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

const char* tokenTypeNames[] =
        {"COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN",
         "RIGHT_PAREN", "COLON", "COLON_DASH", "MULTIPLY",
         "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES",
         "ID", "STRING", "COMMENT", "UNDEFINED", "EOF"};

const char* tokenTypeName(TokenType type) {
    return tokenTypeNames[(int) type];
}

#endif //UNTITLED_TOKENTYPE_H
