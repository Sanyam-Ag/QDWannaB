#pragma once
#include "command.hpp"
#include "csv_loader.hpp"
#include<stdexcept>

namespace cli{

    class LoadCommand : public Command{
    public:
        std::string name() const override{ return "load"; }
        std::string help() const override{ return "Loads the given file"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            if (args.size() != 1) {
                std::cout << "Usage: load <file.csv>\n";
                return;
            }

            try {
                ctx.dataset = core::CSVLoader::load(args[0]);
                std::cout << "Loaded dataset from " << args[0] << "\n";
            }
            catch (const std::exception& e) {
                std::cout << "Load failed: " << e.what() << "\n";
            }
        }
    };

}