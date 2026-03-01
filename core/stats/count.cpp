#include "count.hpp"
#include <stdexcept>

double count(const TimeSeries& ts){
    const auto& v = ts.values();

    return v.size();
}
