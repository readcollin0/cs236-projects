//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONQMARK_H
#define UNTITLED_AUTOMATONQMARK_H

#include "AutomatonSingleChar.h"

class AutomatonQMark : public AutomatonSingleChar {
public:
    AutomatonQMark() : AutomatonSingleChar('?', TokenType::Q_MARK) {}
};

#endif //UNTITLED_AUTOMATONQMARK_H
