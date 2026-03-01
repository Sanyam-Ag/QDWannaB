 
add_executable(tsengine 
    main.cpp
    repl.cpp
    commands/command_registry.cpp
    parser.cpp
)

target_include_directories(tsengine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/commands
    ${CMAKE_CURRENT_SOURCE_DIR}/commands/stats
)

target_link_libraries(tsengine PRIVATE tscore)
