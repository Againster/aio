//
// Created by root on 2/7/18.
//

#ifndef TESTCC_CONNECTION_H
#define TESTCC_CONNECTION_H

#include "config.h"
#include "core.h"

struct listening_s {
    int fd;
    struct sockaddr* sockaddr;
    socklen_t socklen;

    int type;
    int backlog;

    char* addr_text;
};

typedef struct {

} Connection;

int open_listening_socket(Cycle* cycle);


#endif //TESTCC_CONNECTION_H
