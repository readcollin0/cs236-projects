//
// Created by collin on 2/3/21.
//

#include "TokenType.h"

const char* tokenTypeNames[] =
        {"COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN",
         "RIGHT_PAREN", "COLON", "COLON_DASH", "MULTIPLY",
         "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES",
         "ID", "STRING", "COMMENT", "UNDEFINED", "EOF"};

const char* tokenTypeName(TokenType type) {
    return tokenTypeNames[(int) type];
}