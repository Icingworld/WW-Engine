add_subdirectory(core)
add_subdirectory(function)
add_subdirectory(platform)
add_subdirectory(resource)

# 创建 ww-engine 库
add_library(ww-engine INTERFACE)

# 链接 ww-engine 库
target_link_libraries(ww-engine INTERFACE
    engine-core
    # engine-function
    # engine-platform
    # engine-resource
    third-party
)