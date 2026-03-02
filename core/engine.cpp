#include "engine.hpp"

using namespace core;

double Engine::mean(const TimeSeries& ts){
    return ::mean(ts);
}

double Engine::variance(const TimeSeries& ts){
    return ::variance(ts);
}

double Engine::stddev(const TimeSeries& ts){
    return ::stddev(ts);
}

double Engine::min(const TimeSeries& ts){
    return ::min(ts);
}

double Engine::max(const TimeSeries& ts){
    return ::max(ts);
}

double Engine::count(const TimeSeries& ts){
    return ::count(ts);
}

double Engine::covariance(const TimeSeries& tsx, const TimeSeries& tsy){
    return ::covariance(tsx, tsy);
}

double Engine::correlation(const TimeSeries& tsx, const TimeSeries& tsy){
    return ::correlation(tsx, tsy);
}