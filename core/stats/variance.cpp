#include "stats/mean.hpp"
#include "stats/variance.hpp"

double variance(const TimeSeries& ts){
    const auto& v = ts.values();
    double mean_ts = mean(ts);
    double accum = 0.0;

    for(double x : v){
        double diff = x - mean_ts;
        accum += diff * diff;
    }

    return accum/static_cast<double>(v.size());
}