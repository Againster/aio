//
// Created by root on 1/25/18.
//

#ifndef TESTCC_QUEUE_MEM_POOL_H
#define TESTCC_QUEUE_MEM_POOL_H

#include "mem_pool.h"

class QueueMemPool : public MemPool {
    void create(size_t);
    void destory();
    void reset();

    void* alloc(size_t);
    void* calloc(size_t, size_t);
    void free(void*);
};


#endif //TESTCC_QUEUE_MEM_POOL_H
