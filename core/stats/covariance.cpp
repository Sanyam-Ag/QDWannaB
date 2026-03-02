#include <cmath>
#include "covariance.hpp"
#include "mean.hpp"

double covariance(const TimeSeries& tsx, const TimeSeries& tsy){
    const auto& vx = tsx.values(), vy = tsy.values();
    double meanx = mean(tsx), meany = mean(tsy);

    long long unsigned n = vx.size();
    double accum = 0;

    for(int i=0; i<n; ++i){
        accum = accum + (vx[i] - meanx) * (vy[i] - meany);
    }


    return accum/static_cast<double>(n);
}