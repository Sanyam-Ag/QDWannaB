#pragma once
#include "command.hpp"
#include<stdexcept>

namespace cli{

    class ExitCommand : public Command{
    public:
        std::string name() const override{ return "exit"; }
        std::string help() const override{ return "Exit the program"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            throw std::runtime_error("exit");
        }
    };

}