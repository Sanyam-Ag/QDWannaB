#pragma once
#include "timeseries.hpp"
#include "mean.hpp"
#include "variance.hpp"
#include "stddev.hpp"
#include "minmax.hpp"
#include "count.hpp"
#include <string>

namespace core{
    class Engine {
    public:
        TimeSeries load(const std::string& path, const std::string& column);

        static double mean(const TimeSeries& ts);
        static double variance(const TimeSeries& ts);
        static double stddev(const TimeSeries& ts);
        static double min(const TimeSeries& ts);
        static double max(const TimeSeries& ts);
        static double count(const TimeSeries& ts);
    };
}
