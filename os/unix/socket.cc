//
// Created by root on 2/7/18.
//

#include "socket.h"


int nonblocking(int fd) {
    int nb;
    nb = 1;
    return ioctl(fd, FIONBIO, &nb);
};