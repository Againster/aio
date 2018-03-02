//
// Created by root on 2/2/18.
//

#ifndef TESTCC_IPC_H
#define TESTCC_IPC_H


#include <cstdlib>

class Ipc {
public:
    const char* name;
    virtual int init() = 0;
    virtual int done() = 0;
    virtual int push(void* data, size_t size) = 0;
    virtual int pull(void* data, size_t size) = 0;
};


#endif //TESTCC_IPC_H
