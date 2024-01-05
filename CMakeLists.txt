cmake_minimum_required(VERSION 3.14)

project(NLog LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(TEST "Build test for NLog" ON)
set(buf_size 1024 CACHE STRING "Default max size for each log")

if (TEST)
    find_package(GTest REQUIRED)
endif()

add_compile_definitions(NLOG_BUF_SIZE=${buf_size})

set(INC include/nlog)
set(SRC src)

add_library(NLog SHARED
  ${INC}/NLog_global.h
  ${INC}/NLog.h
  ${INC}/LogComponent.h
  ${INC}/NLogger.h
  ${INC}/DefaultTree.h
  ${SRC}/NLog.cpp
  ${SRC}/LogComponent.cpp
  ${SRC}/NLogger.cpp
  ${SRC}/DefaultTree.cpp
)

include_directories(${INC})
target_compile_definitions(NLog PRIVATE NLOG_LIBRARY)

# Installation instructions
install(TARGETS NLog
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

if (TEST)
    add_executable(NLogTests
                   tests/basic_test.cpp
    )
    target_link_libraries(NLogTests PRIVATE NLog GTest::GTest GTest::Main)
endif()
