add_executable(ts_tests
    tests.cpp
    test_timeseries.cpp
    test_dataset.cpp
    test_mean.cpp
    test_variance.cpp
    test_dataset.cpp
)

target_link_libraries(ts_tests PRIVATE tscore)
 
