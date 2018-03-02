//
// Created by root on 1/26/18.
//

#include "epoll.h"


int Epoll::add(Event* ev, int event, unsigned int flags) {

};

int Epoll::del(Event* ev, int event, unsigned int flags) {

};

int Epoll::enable(Event* ev, int event, unsigned int flags) {

};

int Epoll::disable(Event* ev, int event, unsigned int flags) {

};

int Epoll::add_conn(Event* ev, int event, unsigned int flags) {

};

int Epoll::del_conn(Event* ev, int event, unsigned int flags) {

};

int Epoll::notify(event_handler_pt handler) {

};

int Epoll::process_event(void* cycle, unsigned long timer, unsigned int
flags) {

};

int Epoll::init(void* cycle, unsigned long timer) {

};

void Epoll::done(void* cycle) {

};
