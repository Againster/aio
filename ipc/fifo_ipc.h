//
// Created by root on 2/2/18.
//

#ifndef TESTCC_FIFO_IPC_H
#define TESTCC_FIFO_IPC_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
using namespace std;

#include "ipc.h"
class FifoIpc: public Ipc {
public:
    FifoIpc(const string channel, bool peer = false);
    int init();
    int done();
    int push(void* data, size_t size);
    int pull(void* data, size_t size);

    ~FifoIpc();
private:

    string fifo_path_0_;
    string fifo_path_1_;
    mode_t mode_;

    int fifo_0_fd_;
    int fifo_1_fd_;

    bool peer;
};


#endif //TESTCC_FIFO_IPC_H
