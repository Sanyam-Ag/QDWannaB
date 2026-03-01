#include "engine.hpp"
#include<fstream>
#include<sstream>
#include<stdexcept>

using namespace core;

TimeSeries Engine::load(const std::string& path, const std::string& column){
    std::ifstream file(path);
    if(!file.is_open()){
        throw std::runtime_error("Failed to load csv file");
    }

    std::string line;

    std::vector<double> values;

    while(getline(file, line)){
        std::stringstream ss(line);
        std::string valpoint;

        std::getline(ss, valpoint, ',');
        values.push_back(std::stod(valpoint));
    }
    
    return TimeSeries(std::move(values));
}

double Engine::mean(const TimeSeries& ts) {
    return ::mean(ts);
}

double Engine::variance(const TimeSeries& ts) {
    return ::variance(ts);
}