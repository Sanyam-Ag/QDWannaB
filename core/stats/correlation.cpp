#include <cmath>
#include<stdexcept>
#include "correlation.hpp"
#include "stddev.hpp"
#include "covariance.hpp"

double correlation(const TimeSeries& tsx, const TimeSeries& tsy){
    const auto& vx = tsx.values();
    const auto& vy = tsy.values();

    if(vx.size() != vy.size())  throw std::runtime_error("Series length mismatch");
    else if(vx.size() < 2)  throw std::runtime_error("Series length too small"); 
    
    double stddevx = stddev(tsx), stddevy = stddev(tsy);
    double cov = covariance(tsx, tsy);

    if(stddevx == 0 || stddevy == 0)    throw std::runtime_error("Undefined Correlation: Standard Deviation is ZERO"); 

    return (cov/(stddevx * stddevy));
}
