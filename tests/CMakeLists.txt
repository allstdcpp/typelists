
set(CMAKE_CXX_STANDARD 20)
add_executable(tests 
    main.cpp
    unique_tests.cpp
    unique_typelist_tests.cpp
    fill_typelist_tests.cpp
)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE typelists)
