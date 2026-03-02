#pragma once
#include "dataset.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>

namespace core{
    class CSVLoader{
        public:
            static Dataset load(const std::string& path){
                std::ifstream file(path);
                
                if(!file.is_open()) throw std::runtime_error("Failed to load csv file");

                std::string line;
                std::vector<std::string> headers;

                if(!std::getline(file, line))  throw std::runtime_error("Empty file");     // Read header

                {
                    std::stringstream ss(line);
                    std::string cell;
                    while(std::getline(ss, cell, ','))  headers.push_back(cell);
                }

                std::vector<std::vector<double>> columns(headers.size());

                // Read rows
                while(std::getline(file, line)){
                    std::stringstream ss(line);
                    std::string cell;
                    size_t col = 0;

                    while(std::getline(ss, cell, ',')){
                        if (col >= columns.size())  throw std::runtime_error("Column mismatch");

                        columns[col].push_back(std::stod(cell));
                        ++col;
                    }

                    if (col != columns.size())  throw std::runtime_error("Row column mismatch");
                }

                Dataset ds;

                for (size_t i = 0; i < headers.size(); ++i) {
                    ds.add_column(headers[i], TimeSeries(columns[i]));
                }

                return ds;
            }
    };
}