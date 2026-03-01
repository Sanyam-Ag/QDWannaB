#include <cmath>
#include "stddev.hpp"
#include "variance.hpp"

double stddev(const TimeSeries& ts){
    const auto& v = ts.values();
    double stddev_ts = std::sqrt(variance(ts));

    return stddev_ts;
}