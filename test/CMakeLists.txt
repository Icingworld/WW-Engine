file(GLOB_RECURSE SOURCE_FILES "*.cpp")

add_executable(test ${SOURCE_FILES})

target_link_libraries(test PRIVATE ww-engine)

set(DEST_DIR "${CMAKE_BINARY_DIR}/test/assets")

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "${DEST_DIR}"
    COMMENT "Copying assets to build directory"
)
