add_library(tscore
    data/timeseries.cpp
    data/dataset.cpp
    stats/mean.cpp
    stats/variance.cpp
    stats/stddev.cpp
    stats/minmax.cpp
    stats/count.cpp
    stats/covariance.cpp
    stats/correlation.cpp
    engine.cpp
    csv_loader.cpp
)

target_include_directories(tscore PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/stats
${CMAKE_CURRENT_SOURCE_DIR}/data
)
 
