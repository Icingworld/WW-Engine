# 递归搜索所有源文件
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 创建 core 库
add_library(core STATIC ${SOURCES})

# 添加搜索路径
target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 添加依赖项
target_link_libraries(core PUBLIC functions platform third-party)