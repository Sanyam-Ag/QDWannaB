#include "command_registry.hpp"

namespace cli{

    void CommandRegistry::register_command(std::unique_ptr<Command> cmd){
        commands_[cmd->name()] = std::move(cmd);
    }

    Command* CommandRegistry::get(const std::string& name) const{
        auto it = commands_.find(name);
        if (it != commands_.end()){
            return it->second.get();
        }
        return nullptr;
    }

    std::vector<Command*> CommandRegistry::list() const{
        std::vector<Command*> result;
        for (const auto& pair : commands_){
            result.push_back(pair.second.get());
        }
        return result;
    }

}
