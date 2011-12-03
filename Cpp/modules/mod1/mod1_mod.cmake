set(MOD1_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${MOD1_DIR}/include)

SET( MOD1_HDRS
${MOD1_DIR}/include/Lindenmayer.hpp
)

SET( MOD1_SRC
${MOD1_DIR}/src/Lindenmayer.cpp
)

add_library( base SHARED
${MOD1_HDRS}
${MOD1_SRC}
)

add_executable( main ${MOD1_DIR}/src/main.cpp )

target_link_libraries( main base )
