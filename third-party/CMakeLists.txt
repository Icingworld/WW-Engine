# 添加 glfw 子模块
add_subdirectory(glfw)

# 创建 glad 库
add_library(glad STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
)

# 添加 glad 搜索路径
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
)

# 添加 glm 子模块
add_subdirectory(glm)

# 创建 stb_image 库
add_library(stb_image INTERFACE)

# 添加 stb_image 搜索路径
target_include_directories(stb_image INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/stb_image
)

# 创建 third-party 库
add_library(third-party INTERFACE)

# 添加 third-party 搜索路径
target_include_directories(third-party INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 搜索 OpenGL
find_package(OpenGL REQUIRED)

# 添加 third-party 依赖项
target_link_libraries(third-party INTERFACE
    OpenGL::GL
    glfw
    glad
    glm
    stb_image
)