file(GLOB_RECURSE SOURCE_FILES "*.cpp")

add_executable(test ${SOURCE_FILES})

target_link_libraries(test PRIVATE ww-engine)