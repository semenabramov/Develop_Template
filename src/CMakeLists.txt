
file(GLOB SRCS "*.c*")
file(GLOB HDRS "*.h*")

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARY})