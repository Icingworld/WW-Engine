# 搜索源文件
file(GLOB_RECURSE SOURCE_FILES *.cpp)

# 创建 engine-platform 库
add_library(engine-platform STATIC ${SOURCE_FILES})

# 设置 engine-platform 搜索路径
target_include_directories(engine-platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/file_system
)

# 添加 engine-platform 依赖项
target_link_libraries(engine-platform PUBLIC
    ww-engine
)