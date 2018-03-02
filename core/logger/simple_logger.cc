//
// Created by root on 1/26/18.
//

#include "simple_logger.h"

#define FMT_BUF(buf, fmt) \
    va_list args; \
    va_start(args, fmt); \
    vsprintf(buf, fmt, args); \
    va_end(args);

static char sprint_buf[1024];

void SimpleLogger::fatal(int no, const char* format, ...) {
    FMT_BUF(sprint_buf, format);
    printf("%d:\t", no);
    printf(sprint_buf);
};

void SimpleLogger::error(int no, const char* format, ...) {
    FMT_BUF(sprint_buf, format);
    printf("%d:\t", no);
    printf(sprint_buf);
};

void SimpleLogger::warn(int no, const char* format, ...) {
    FMT_BUF(sprint_buf, format);
    printf("%d:\t", no);
    printf(sprint_buf);
};

void SimpleLogger::info(int no, const char* format, ...) {
    FMT_BUF(sprint_buf, format);
    printf("%d:\t", no);
    printf(sprint_buf);
};

void SimpleLogger::debug(int no, const char* format, ...) {
    FMT_BUF(sprint_buf, format);
    printf("%d:\t", no);
    printf(sprint_buf);
};