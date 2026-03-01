#include "dataset.hpp"
#include<stdexcept>

namespace core{
    void Dataset::add_column(const std::string& name, const TimeSeries& ts){
        data_.insert_or_assign(name, ts);
    }

    bool Dataset::has_column(const std::string& name) const{
        return (data_.find(name) != data_.end());
    }

    const TimeSeries& Dataset::column(const std::string& name) const{
        auto col = data_.find(name);
        if(col == data_.end()){
            throw std::runtime_error("Column not found: " + name);
        }
        return col->second;
    }

    std::vector<std::string> Dataset::columns() const{
        std::vector<std::string> collist;

        for(auto &pair : data_){
            collist.push_back(pair.first);
        }

        return collist;
    }
};