//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONLEFTPAREN_H
#define UNTITLED_AUTOMATONLEFTPAREN_H

#include "AutomatonSingleChar.h"

class AutomatonLeftParen : public AutomatonSingleChar {
public:
    AutomatonLeftParen() : AutomatonSingleChar('(', TokenType::LEFT_PAREN) {}
};

#endif //UNTITLED_AUTOMATONLEFTPAREN_H
