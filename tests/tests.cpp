#include "stats/mean.hpp"
#include "data/timeseries.hpp"
#include <cassert>

void test_timeseries();
void test_variance();
void test_mean();

int main() {
    test_timeseries();
    test_mean();
    test_variance();
}
