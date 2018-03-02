//
// Created by root on 1/26/18.
//

#ifndef TESTCC_SELECT_MODEL_H
#define TESTCC_SELECT_MODEL_H

#include "config.h"
#include "core.h"
#include "event_module.h"

class Select : public EventModule {
public:
    virtual int add(Event *ev, int event, unsigned int flags);

    virtual int del(Event *ev, int event, unsigned int flags);

    virtual int enable(Event *ev, int event, unsigned int flags);

    virtual int disable(Event *ev, int event, unsigned int flags);

    virtual int add_conn(Event *ev, int event, unsigned int flags);

    virtual int del_conn(Event *ev, int event, unsigned int flags);

    virtual int notify(event_handler_pt handler);

    virtual int
    process_event(void *cycle, unsigned long timer, unsigned int flags);

    virtual int init(void *cycle, unsigned long timer);

    virtual void done(void *cycle);

};


#endif //TESTCC_SELECT_MODEL_H
