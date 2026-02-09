#include "data/timeseries.hpp"
#include <cassert>

void test_timeseries() {
    TimeSeries ts({1.0, 2.0, 3.0});
    assert(ts.size() == 3);
    assert(ts.values()[0] == 1.0);

    bool thrown = false;
    try {
        TimeSeries bad({});
    } catch (...) {
        thrown = true;
    }
    assert(thrown);
}
