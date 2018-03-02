//
// Created by root on 1/26/18.
//

#include "select.h"
#include "../event.h"

int Select::add(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::del(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::enable(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::disable(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::add_conn(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::del_conn(Event *ev, int event, unsigned int flags) {
    return 0;
}

int Select::notify(event_handler_pt handler) {
    return 0;
}

int
Select::process_event(void *cycle, unsigned long timer, unsigned int flags) {
    return 0;
}

int Select::init(void *cycle, unsigned long timer) {
    return 0;
}

void Select::done(void *cycle) {

}
