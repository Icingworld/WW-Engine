cmake_minimum_required(VERSION 3.10)
project(ww-engine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子模块
add_subdirectory(core)
add_subdirectory(functions)
add_subdirectory(platform)
# add_subdirectory(resources)
add_subdirectory(third-party)

# 创建 ww-engine 库
add_library(ww-engine INTERFACE)

# 添加 ww-engine 搜索路径
target_include_directories(ww-engine INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/functions
    ${CMAKE_CURRENT_SOURCE_DIR}/platform
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

# 添加依赖项
target_link_libraries(ww-engine INTERFACE
    core
    functions
    platform
    # resources
    third-party
)

# 设置 test 选项
option(ENABLE_TEST "Enable Test" OFF)

# 编译引擎测试
if (ENABLE_TEST)
    message(STATUS "Test enabled")
    add_subdirectory(test)
else()
    message(STATUS "Test disabled")
endif()
