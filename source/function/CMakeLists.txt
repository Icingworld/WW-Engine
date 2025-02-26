# 搜索源文件
file(GLOB_RECURSE SOURCE_FILES *.cpp)

# 创建 engine-function 库
add_library(engine-function STATIC ${SOURCE_FILES})

# 设置 engine-function 搜索路径
target_include_directories(engine-function PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/input
)

# 添加 engine-function 依赖项
target_link_libraries(engine-function PUBLIC
    third-party
)