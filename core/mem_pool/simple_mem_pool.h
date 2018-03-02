//
// Created by root on 1/25/18.
//

#ifndef TESTCC_SIMPLE_MEM_POOL_H
#define TESTCC_SIMPLE_MEM_POOL_H

#include <cstdlib>
#include <list>
#include "mem_pool.h"

using namespace std;

class SimpleMemPool : public MemPool {
    void create(size_t);
    void destory();
    void reset();

    void* alloc(size_t);
    void* calloc(size_t, size_t);
    void free(void*);

    struct cleanup_s {
        cleanup_pt handler;
        void* data;
    };

    list<cleanup_s*> cleanup_s_l;
    void cleanup(cleanup_pt, void*);
};



#endif //TESTCC_SIMPLE_MEM_POOL_H
