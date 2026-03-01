#pragma once
#include "data/timeseries.hpp"
#include "stats/mean.hpp"
#include "stats/variance.hpp"
#include <string>

namespace core{
    class Engine {
    public:
        TimeSeries load(const std::string& path, const std::string& column);

        static double mean(const TimeSeries& ts);
        static double variance(const TimeSeries& ts);
    };
}
