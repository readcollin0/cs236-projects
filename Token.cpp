//
// Created by collin on 2/3/21.
//

#include "Token.h"

std::ostream& operator<<(std::ostream& out, const Token& token) {
    out << "(" << tokenTypeName(token.type) << ",\"" << token.str << "\"," << token.lineNum << ")";
    return out;
}