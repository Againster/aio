cmake_minimum_required(VERSION 3.7)
project(testcc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

include_directories(core)
include_directories(event)
include_directories(os/unix)

set(SOURCE_FILES main.cc core/mem_pool/mem_pool.h core/mem_pool/queue_mem_pool.cc core/mem_pool/queue_mem_pool.h core/mem_pool/simple_mem_pool.cc core/mem_pool/simple_mem_pool.h event/modules/event_module.h core/logger/logger.h core/logger/simple_logger.cc core/logger/simple_logger.h event/event.cc event/event.h event/modules/epoll.cc event/modules/epoll.h event/modules/select.cc event/modules/select.h core/config.h core/mem_pool/allocator.h ipc/ipc.h ipc/fifo_ipc.cc ipc/fifo_ipc.h core/cycle.cc core/cycle.h core/connection.cc core/connection.h core/core.h os/unix/socket.cc os/unix/socket.h os/unix/unix_config.h core/mem_pool/queue_allocator.cc core/mem_pool/queue_allocator.h core/mem_pool/simple_allocator.cc core/mem_pool/simple_allocator.h)
add_executable(testcc ${SOURCE_FILES})