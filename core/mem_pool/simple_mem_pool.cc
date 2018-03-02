//
// Created by root on 1/25/18.
//

#include "simple_mem_pool.h"


void SimpleMemPool::create(size_t s) {
    return;
};


void SimpleMemPool::reset() {
    return;
}

void SimpleMemPool::destory() {
    return;
}


void* SimpleMemPool::alloc(size_t s) {
    return malloc(s);
}


void* SimpleMemPool::calloc(size_t num, size_t s) {
    return std::calloc(num, s);
}


void SimpleMemPool::free(void* v) {
    return free(v);
}

void SimpleMemPool::cleanup(cleanup_pt pt, void *v) {
}