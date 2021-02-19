set(target "myfunctoin")

file(GLOB hdrs "*.h*" "${PROJECT_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})