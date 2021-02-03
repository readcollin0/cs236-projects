//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATONPERIOD_H
#define UNTITLED_AUTOMATONPERIOD_H

#include "AutomatonSingleChar.h"

class AutomatonPeriod : public AutomatonSingleChar {
public:
    AutomatonPeriod() : AutomatonSingleChar('.', TokenType::PERIOD) {}
};

#endif //UNTITLED_AUTOMATONPERIOD_H
