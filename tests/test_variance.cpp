#include "stats/variance.hpp"
#include <cassert>

void test_variance() {
    TimeSeries ts({1.0, 2.0, 3.0});
    double var = variance(ts);
    assert(var > 0.6666 && var < 0.6667);
}
