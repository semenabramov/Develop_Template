set(target "gtest")

file(GLOB SRCS "*.c*")
file(GLOB HDRS "*.h*")
add_library(${target} STATIC ${SRCS} ${HDRS})


if((${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR
    ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") AND
    (${CMAKE_SYSTEM_NAME} MATCHES "Linux"))
    set(pthread "-pthread")
endif()

target_link_libraries(${target} ${pathread})