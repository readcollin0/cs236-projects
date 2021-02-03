//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONCOLON_H
#define UNTITLED_AUTOMATONCOLON_H

#include "AutomatonSingleChar.h"

class AutomatonColon : public AutomatonSingleChar {
public:
    AutomatonColon() : AutomatonSingleChar(':', TokenType::COLON) {}
};

#endif //UNTITLED_AUTOMATONCOLON_H
