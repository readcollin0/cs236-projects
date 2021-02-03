//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONCOMMA_H
#define UNTITLED_AUTOMATONCOMMA_H

#include "AutomatonSingleChar.h"

class AutomatonComma : public AutomatonSingleChar {
public:
    AutomatonComma() : AutomatonSingleChar(',', TokenType::COMMA) {}
};

#endif //UNTITLED_AUTOMATONCOMMA_H
