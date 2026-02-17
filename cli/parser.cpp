#include "parser.hpp"
#include <sstream>

namespace cli{
    ParsedInput Parser::parse(const std::string& line) const{
        ParsedInput result;

        std::istringstream iss(line);
        iss >> result.command;

        std::string arg;
        while (iss >> arg){
            result.args.push_back(arg);
        }

        return result;
    }
}
