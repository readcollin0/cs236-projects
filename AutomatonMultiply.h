//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONMULTIPLY_H
#define UNTITLED_AUTOMATONMULTIPLY_H

#include "AutomatonSingleChar.h"

class AutomatonMultiply : public AutomatonSingleChar {
public:
    AutomatonMultiply() : AutomatonSingleChar('*', TokenType::MULTIPLY) {}
};

#endif //UNTITLED_AUTOMATONMULTIPLY_H
