#pragma once
#include "timeseries.hpp"
#include "mean.hpp"
#include "variance.hpp"
#include "stddev.hpp"
#include "minmax.hpp"
#include "count.hpp"
#include "covariance.hpp"
#include "correlation.hpp"
#include <string>

namespace core{
    class Engine {
        public:
            static double mean(const TimeSeries& ts);
            static double variance(const TimeSeries& ts);
            static double stddev(const TimeSeries& ts);
            static double min(const TimeSeries& ts);
            static double max(const TimeSeries& ts);
            static double count(const TimeSeries& ts);
            static double covariance(const TimeSeries& tsx, const TimeSeries& tsy);
            static double correlation(const TimeSeries& tsx, const TimeSeries& tsy);
        };
}
