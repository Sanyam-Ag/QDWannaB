#include "stats/mean.hpp"
#include <stdexcept>

double mean(const TimeSeries& ts){
    const auto& v = ts.values();
    double sum = 0.0;

    for (double x : v){
        sum += x;
    }

    return sum / static_cast<double>(v.size());
}
