//
// Created by root on 2/7/18.
//

#ifndef TESTCC_CYCLE_H
#define TESTCC_CYCLE_H

#include "config.h"
#include "core.h"

struct cycle_s {
    Logger* log;
    MemPool* mem;

    vector<Listening*>* listening;
};

class CoreCycle {

};


#endif //TESTCC_CYCLE_H
