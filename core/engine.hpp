#pragma once
#include "data/timeseries.hpp"
#include "stats/mean.hpp"
#include "stats/variance.hpp"
#include <string>

class Engine {
public:
    TimeSeries load(const std::string& path, const std::string& column);

    double mean(const TimeSeries& ts);
    double variance(const TimeSeries& ts);
};
