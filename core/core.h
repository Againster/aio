//
// Created by root on 2/7/18.
//

#ifndef TESTCC_CORE_H
#define TESTCC_CORE_H

#include "config.h"


#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>



#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>


#include <vector>


typedef struct listening_s Listening;
typedef struct cycle_s Cycle;

#include "mem_pool/mem_pool.h"
#include "mem_pool/simple_mem_pool.h"
#include "logger/logger.h"
#include "logger/simple_logger.h"


#include "cycle.h"
#include "connection.h"
#include "socket.h"

#endif //TESTCC_CORE_H
