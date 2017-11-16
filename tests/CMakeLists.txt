set(SRCS
    main.cpp
    util/memory_util.cpp
    )

include(CreateDirectoryGroups)
create_directory_groups(${SRCS})

add_executable(libacorn_tests ${SRCS})
target_link_libraries(libacorn_tests PRIVATE catch libacorn)
target_include_directories(libacorn_tests PRIVATE . ../src)
target_compile_options(libacorn_tests PRIVATE ${LIBACORN_CXX_FLAGS})

add_test(libacorn_tests libacorn_tests)
