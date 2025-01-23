# 递归搜索所有源文件
file(GLOB_RECURSE SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 创建 platform 库
add_library(platform STATIC ${SOURCE_FILE})

# 添加搜索路径
target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 添加依赖项
target_link_libraries(platform PUBLIC core functions third-party)