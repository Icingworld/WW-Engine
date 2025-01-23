# 递归搜索所有源文件
file(GLOB_RECURSE SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 创建 functions 库
add_library(functions STATIC ${SOURCE_FILE})

# 添加搜索路径
target_include_directories(functions PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 添加依赖项
target_link_libraries(functions PUBLIC core third-party)