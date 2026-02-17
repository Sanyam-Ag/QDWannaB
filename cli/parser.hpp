#pragma once
#include <string>
#include <vector>

namespace cli{
    struct ParsedInput{
        std::string command;
        std::vector<std::string> args;
    };

    class Parser{
        public:
            ParsedInput parse(const std::string& line) const;
    };
}
