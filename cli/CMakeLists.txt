 
add_executable(tsengine 
    main.cpp
    repl.cpp
    command_registry.cpp
    parser.cpp
)
target_link_libraries(tsengine PRIVATE tscore)
