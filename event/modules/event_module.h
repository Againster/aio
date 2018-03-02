//
// Created by root on 1/25/18.
//

#ifndef TESTCC_IOMODEL_H
#define TESTCC_IOMODEL_H

#include "event.h"

typedef void (*event_handler_pt)(Event* ev);

class EventModule {
public:

    const char* name;

    virtual int add(Event* ev, int event, unsigned int flags) = 0;
    virtual int del(Event* ev, int event, unsigned int flags) = 0;

    virtual int enable(Event* ev, int event, unsigned int flags) = 0;
    virtual int disable(Event* ev, int event, unsigned int flags) = 0;

    virtual int add_conn(Event* ev, int event, unsigned int flags) = 0;
    virtual int del_conn(Event* ev, int event, unsigned int flags) = 0;

    virtual int notify(event_handler_pt handler) = 0;

    virtual int process_event(void* cycle, unsigned long timer, unsigned int
    flags) = 0;

    virtual int init(void* cycle, unsigned long timer) = 0;
    virtual void done(void* cycle) = 0;
};


#endif //TESTCC_IOMODEL_H
