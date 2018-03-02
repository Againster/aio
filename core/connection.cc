//
// Created by root on 2/7/18.
//

#include "connection.h"

int open_listening_socket(Cycle* cycle) {
    int fd;
    int size;
    int reuseaddr;
    Listening* ls;

    for (int i = 0; i < cycle->listening->size(); i++) {
        ls = cycle->listening->at(i);

        fd = socket(ls->sockaddr->sa_family, ls->type, 0);
        ls->fd = fd;

        if (fd == -1) {
            cycle->log->error(0, "socket failed");
            return -1;
        }

        if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int))
            == -1) {
            cycle->log->error(0, "setsockopt failed");
            if (close(fd) == -1) {
                cycle->log->error(0, "%s failed", ls->addr_text);
            }
            return -1;
        }

        if (nonblocking(fd) == -1) {
            cycle->log->error(errno, "nonblocking failed");
            return -1;
        }

        if (bind(fd, ls->sockaddr, ls->socklen) == -1) {
            cycle->log->error(errno, "bind failed");
            return (int)errno;
        }

        if (listen(fd, ls->backlog) == -1) {
            cycle->log->error(errno, "listen failed");
            return (int)errno;
        }


    }

    return 0;
};