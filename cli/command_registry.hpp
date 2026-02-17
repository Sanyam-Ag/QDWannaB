#pragma once
#include "command.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace cli{
    class CommandRegistry{
        public:
            void register_command(std::unique_ptr<Command> cmd);
            Command* get(const std::string& name) const;
            std::vector<Command*> list() const;

        private:
            std::unordered_map<std::string, std::unique_ptr<Command>> commands_;
        };
}
