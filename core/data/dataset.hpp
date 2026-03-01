#pragma once
#include "timeseries.hpp"
#include <string>
#include <unordered_map>
#include <vector>

namespace core{

class Dataset{
public:
    void add_column(const std::string& name, const TimeSeries& ts);

    bool has_column(const std::string& name) const;

    const TimeSeries& column(const std::string& name) const;

    std::vector<std::string> columns() const;

private:
    std::unordered_map<std::string, TimeSeries> data_;
};

}
