#include"stats/mean.hpp"
#include<stdexcept>

double mean(const TimeSeries &ts){
    const auto &val = ts.values();
    double sum = 0.0;

    for(auto x : val){
        sum += x;
    }

    return sum/static_cast<double>(ts.size());
}