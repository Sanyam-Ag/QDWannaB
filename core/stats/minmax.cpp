#include <algorithm>
#include<stdexcept>
#include "minmax.hpp"

double min(const TimeSeries& ts){
    const auto& v = ts.values();
    
    if(v.size() == 0)   throw std::runtime_error("Empty dataset column passed");

    auto it = std::min_element(v.begin(), v.end());
    return *it;
}

double max(const TimeSeries& ts){
    const auto& v = ts.values();
    
    if(v.size() == 0)   throw std::runtime_error("Empty dataset column passed");

    auto it = std::max_element(v.begin(), v.end());
    return *it;
}