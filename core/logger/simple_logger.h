//
// Created by root on 1/26/18.
//

#ifndef TESTCC_SIMPLE_LOGGER_H
#define TESTCC_SIMPLE_LOGGER_H

#include "config.h"
#include "core.h"
#include "logger.h"

class SimpleLogger : public Logger {
public:
    void fatal(int no, const char* format, ...);
    void error(int no, const char* format, ...);
    void warn(int no, const char* format, ...);
    void info(int no, const char* format, ...);
    void debug(int no, const char* format, ...);
};


#endif //TESTCC_SIMPLE_LOGGER_H
