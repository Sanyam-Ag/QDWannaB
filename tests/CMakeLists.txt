add_executable(ts_tests
    tests.cpp
    test_timeseries.cpp
    test_mean.cpp
    test_variance.cpp
)

target_link_libraries(ts_tests PRIVATE tscore)
 
