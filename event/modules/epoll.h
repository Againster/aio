//
// Created by root on 1/26/18.
//

#ifndef TESTCC_EPOLL_MODEL_H
#define TESTCC_EPOLL_MODEL_H

#include "config.h"
#include "core.h"
#include "event_module.h"

class Epoll : public EventModule {
    Epoll (){
        this->name = "epoll";
    }

    int add(Event* ev, int event, unsigned int flags);
    int del(Event* ev, int event, unsigned int flags);

    int enable(Event* ev, int event, unsigned int flags);
    int disable(Event* ev, int event, unsigned int flags);

    int add_conn(Event* ev, int event, unsigned int flags);
    int del_conn(Event* ev, int event, unsigned int flags);

    int notify(event_handler_pt handler);

    int process_event(void* cycle, unsigned long timer, unsigned int flags);

    int init(void* cycle, unsigned long timer);
    void done(void* cycle);
};


#endif //TESTCC_EPOLL_MODEL_H
