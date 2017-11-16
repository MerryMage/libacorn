set(SRCS
    util/memory_util.cpp
    )

set(HEADERS
    util/memory_util.hpp
    )

include(CreateDirectoryGroups)
create_directory_groups(${SRCS} ${HEADERS})

add_library(libacorn ${SRCS} ${HEADERS})
target_include_directories(libacorn PUBLIC ..)
target_compile_options(libacorn PRIVATE ${LIBACORN_CXX_FLAGS})
