# 搜索源文件
file(GLOB_RECURSE SOURCE_FILES *.cpp)

# 创建 engine-core 库
add_library(engine-core STATIC ${SOURCE_FILES})

# 设置 engine-core 搜索路径
target_include_directories(engine-core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/assert
    ${CMAKE_CURRENT_SOURCE_DIR}/log
    ${CMAKE_CURRENT_SOURCE_DIR}/math
    ${CMAKE_CURRENT_SOURCE_DIR}/meta
    ${CMAKE_CURRENT_SOURCE_DIR}/meta/reflection
    ${CMAKE_CURRENT_SOURCE_DIR}/meta/serializer
    ${CMAKE_CURRENT_SOURCE_DIR}/random
    ${CMAKE_CURRENT_SOURCE_DIR}/uuid
)

# 添加 engine-core 依赖项
target_link_libraries(engine-core PUBLIC
    third-party
)