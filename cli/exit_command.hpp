#pragma once
#include "command.hpp"
#include<stdexcept>

namespace cli{

class ExitCommand : public Command{
public:
    std::string name() const override{ return "exit"; }
    std::string help() const override{ return "Exit the program"; }

    void execute(const std::vector<std::string>&) override{
        throw std::runtime_error("exit");
    }
};

}