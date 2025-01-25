# 递归搜索所有源文件
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 创建可执行文件
add_executable(ww_engine_test ${SOURCES})

# 添加依赖项
target_link_libraries(ww_engine_test PUBLIC ww-engine)

# 复制资源文件
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})