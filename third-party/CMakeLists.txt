# 创建 third-party 库
add_library(third-party INTERFACE)

# 添加搜索路径
target_include_directories(third-party INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)