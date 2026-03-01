#include "data/dataset.hpp"
#include "data/timeseries.hpp"
#include <cassert>
#include <iostream>

void test_dataset() {
    using namespace core;

    Dataset ds;

    TimeSeries ts1({1.0, 2.0, 3.0});
    TimeSeries ts2({10.0, 20.0, 30.0});

    // Test add_column
    ds.add_column("a", ts1);
    ds.add_column("b", ts2);

    // Test has_column
    assert(ds.has_column("a"));
    assert(ds.has_column("b"));
    assert(!ds.has_column("c"));

    // Test column retrieval
    const TimeSeries& ref = ds.column("a");
    assert(ref.values().size() == 3);
    assert(ref.values()[0] == 1.0);

    // Test overwrite behavior (if using insert_or_assign)
    TimeSeries ts3({100.0});
    ds.add_column("a", ts3);
    assert(ds.column("a").values()[0] == 100.0);

    // Test missing column throws
    bool threw = false;
    try {
        ds.column("missing");
    } catch (const std::runtime_error&) {
        threw = true;
    }
    assert(threw);

    std::cout << "Dataset tests passed.\n";
}
