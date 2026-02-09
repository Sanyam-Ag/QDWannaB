#include "stats/mean.hpp"
#include <cassert>

void test_mean(){
    TimeSeries ts({1.0, 2.0, 3.0, 4.0});
    double m = mean(ts);
    assert(m == 2.5);
}
