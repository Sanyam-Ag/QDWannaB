add_library(tscore
    data/timeseries.cpp
    data/dataset.cpp
    stats/mean.cpp
    stats/variance.cpp
    engine.cpp
)

target_include_directories(tscore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
 
