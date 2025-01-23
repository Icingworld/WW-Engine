# 添加 glfw 子模块
add_subdirectory(glfw)

# 创建 glad 库
add_library(glad STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
)

# 添加搜索路径
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
)

# 创建 third-party 库
add_library(third-party INTERFACE)

# 添加搜索路径
target_include_directories(third-party INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 搜索 OpenGL
find_package(OpenGL REQUIRED)

# 添加依赖项
target_link_libraries(third-party INTERFACE
    OpenGL::GL
    glfw
    glad
)