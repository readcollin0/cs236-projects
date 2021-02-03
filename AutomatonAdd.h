//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONADD_H
#define UNTITLED_AUTOMATONADD_H

#include "AutomatonSingleChar.h"

class AutomatonAdd : public AutomatonSingleChar {
public:
    AutomatonAdd() : AutomatonSingleChar('+', TokenType::ADD) {}
};

#endif //UNTITLED_AUTOMATONADD_H
