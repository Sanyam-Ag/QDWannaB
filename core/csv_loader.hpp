#pragma once
#include "dataset.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>

namespace core{
    class CSVLoader{
        public:
            static Dataset load(const std::string& path);
    };
}