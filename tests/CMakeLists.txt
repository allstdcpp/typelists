
add_executable(tests 
    main.cpp
    unique_tests.cpp)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE typelists)
