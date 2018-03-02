//
// Created by root on 1/25/18.
//

#ifndef TESTCC_MEM_POOL_H
#define TESTCC_MEM_POOL_H

#include <cstdlib>


class MemPool {
public:
    virtual void create(size_t) = 0;
    virtual void destory() = 0;
    virtual void reset() = 0;

    virtual void* alloc(size_t) = 0;
    virtual void* calloc(size_t num, size_t size) = 0;
    virtual void free(void*) = 0;

    typedef void (*cleanup_pt)(void*);
    virtual void cleanup(cleanup_pt, void*) {};
};


#endif //TESTCC_MEM_POOL_H
