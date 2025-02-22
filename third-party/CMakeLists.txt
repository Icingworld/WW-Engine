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

# 搜索 imgui 源码
set(IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp
)

# 创建 imgui 库
add_library(imgui STATIC
    ${IMGUI_SOURCES}
)

# 添加 imgui 搜索路径
target_include_directories(imgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
)

# 添加 imgui 依赖项
target_link_libraries(imgui PRIVATE
    glfw
    glad
)

# 创建 third-party 库
add_library(third-party INTERFACE)

# 添加 third-party 搜索路径
target_include_directories(third-party INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/stb_image
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
    imgui
)