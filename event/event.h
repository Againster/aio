//
// Created by root on 1/26/18.
//

#ifndef TESTCC_EVENT_H
#define TESTCC_EVENT_H

#include "config.h"
#include "core.h"

typedef struct {
    void* data;
    unsigned write:1;
    unsigned accept:1;
    unsigned disabled:1;
    unsigned oneshot:1;
    unsigned eof:1;
    unsigned error:1;
    unsigned timeout:1;
    unsigned timer_set:1;
} Event;


#endif //TESTCC_EVENT_H
