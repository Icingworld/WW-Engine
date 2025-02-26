# 搜索源文件
file(GLOB_RECURSE SOURCE_FILES *.cpp)

# 创建 engine-resource 库
add_library(engine-resource STATIC ${SOURCE_FILES})

# 设置 engine-resource 搜索路径
target_include_directories(engine-resource PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/resource_manager
)

# 添加 engine-resource 依赖项
target_link_libraries(engine-resource PUBLIC
    ww-engine
)