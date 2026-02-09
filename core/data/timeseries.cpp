#include "data/timeseries.hpp"
#include<stdexcept>

using std::vector;

TimeSeries::TimeSeries(vector<double> values) : values_(std::move(values)){
    if(values_.empty()){
        throw std::invalid_argument("Empty TimeSeries Passed as data");
    }
}

size_t TimeSeries::size() const noexcept{
    return values_.size();
}

const double* TimeSeries::data() const noexcept{
    return values_.data();
}

const vector<double>& TimeSeries::values() const noexcept{
    return values_;
}
