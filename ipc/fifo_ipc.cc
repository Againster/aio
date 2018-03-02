//
// Created by root on 2/2/18.
//

#include "fifo_ipc.h"

FifoIpc::FifoIpc(const string channel, bool peer) {
    name = "fifo";
    fifo_path_0_ = "/tmp/" + channel + "_0.fifo";
    fifo_path_1_ = "/tmp/" + channel + "_1.fifo";
    mode_ = 755;
    this->peer = peer;

};

FifoIpc::~FifoIpc() {

};

int FifoIpc::init() {
    int mk_0, mk_1;
    mk_0 = mkfifo(fifo_path_0_.c_str(), mode_);
    mk_1 = mkfifo(fifo_path_1_.c_str(), mode_);
    if (errno != EEXIST && (mk_0 == -1 || mk_1 == -1) ) {
        return errno;
    }

    if (peer) {
        fifo_1_fd_ = open(fifo_path_0_.c_str(), O_RDWR |
                                                O_APPEND);
        fifo_0_fd_ = open(fifo_path_1_.c_str(), O_RDWR |
                                                O_APPEND);
    } else {
        fifo_0_fd_ = open(fifo_path_0_.c_str(), O_RDWR |
                                                O_APPEND);
        fifo_1_fd_ = open(fifo_path_1_.c_str(), O_RDWR |
                                                O_APPEND);
    }

    if (fifo_0_fd_ == -1 || fifo_1_fd_ == -1) {
        return errno;
    }

    return 0;

};

int FifoIpc::done() {
    int no_0 = 0, no_1 = 0;
    no_0 = close(fifo_0_fd_);
    no_1 = close(fifo_1_fd_);

    unlink(fifo_path_0_.c_str());
    unlink(fifo_path_1_.c_str());

    if (no_0 == -1 || no_1 == -1) {
        return errno;
    }

    return 0;
};

int FifoIpc::push(void* data, size_t size) {
    ssize_t no = 0;
    no = write(fifo_1_fd_, data, size);

    if (no = -1) {
        return errno;
    }

    return no;
};

int FifoIpc::pull(void* data, size_t size) {
    ssize_t no;
    no = read(fifo_0_fd_, data, size);

    if (no == -1) {
        return errno;
    }

    return no;
};

