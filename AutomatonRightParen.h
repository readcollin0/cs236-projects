//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONRIGHTPAREN_H
#define UNTITLED_AUTOMATONRIGHTPAREN_H

#include "AutomatonSingleChar.h"

class AutomatonRightParen : public AutomatonSingleChar {
public:
    AutomatonRightParen() : AutomatonSingleChar(')', TokenType::RIGHT_PAREN) {}
};

#endif //UNTITLED_AUTOMATONRIGHTPAREN_H
