# 递归搜索所有源文件
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 创建 resources 库
add_library(resources STATIC ${SOURCES})

# 添加 resources 搜索路径
target_include_directories(resources PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 添加 resources 依赖项
target_link_libraries(resources PUBLIC core platform)