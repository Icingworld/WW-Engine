cmake_minimum_required(VERSION 3.10)
project(ww-engine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third-party)
add_subdirectory(source)

# 设置 test 选项
option(ENABLE_TEST "Enable Test" OFF)

# 编译引擎测试
if (ENABLE_TEST)
    message(STATUS "Test ON")
    add_subdirectory(test)
else()
    message(STATUS "Test OFF")
endif()