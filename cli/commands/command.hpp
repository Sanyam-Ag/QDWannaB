#pragma once
#include <string>
#include <vector>
#include "context.hpp"

namespace cli{
    class Command{
        public:
            virtual ~Command() = default;

            virtual std::string name() const = 0;
            virtual std::string help() const = 0;
            virtual void execute(Context& ctx, std::vector<std::string>& args) = 0;
    };
}