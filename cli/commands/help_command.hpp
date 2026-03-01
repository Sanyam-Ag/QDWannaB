#pragma once
#include "command.hpp"
#include "command_registry.hpp"
#include <iostream>

namespace cli{
    class HelpCommand : public Command{
        public:
            explicit HelpCommand(const CommandRegistry& registry)
                : registry_(registry){}

            std::string name() const override{ return "help"; }

            std::string help() const override{
                return "List available commands";
            }

            void execute(Context& ctx, std::vector<std::string>& args) override{
                auto commands = registry_.list();
                std::cout << "Command\t\t - Description\n";
                for (auto* cmd : commands){
                    std::cout << cmd->name() << "\t\t - "
                            << cmd->help() << "\n";
                }
            }

        private:
            const CommandRegistry& registry_;
    };

}
