set(target ${TESTS_T})

file(GLOB SRCS "*.c*")
file(GLOB HDRS "*.h*")
add_executable(${target} ${SRCS} ${HDRS})

#target_include_directories(${target} ${PROJECT_NAME})

target_link_libraries(${target} gtest ${PROJECT_LIBRARY})
