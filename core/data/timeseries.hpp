/*
    This header file is used to store the actual Time Series data

    version |   data type supported
    0.1     |   double
    
*/


#pragma once
#include <vector>
#include <cstddef>

using std::vector;

class TimeSeries {
    public:
        explicit TimeSeries(vector<double> values);

        size_t size() const noexcept;
        const double* data() const noexcept;
        const vector<double>& values() const noexcept;

    private:
        vector<double> values_;
};
