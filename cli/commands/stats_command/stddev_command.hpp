#pragma once
#include "command.hpp"
#include "engine.hpp"

namespace cli{
    class StddevCommand : public Command{
    public:
        std::string name() const override{ return "stddev"; }
        std::string help() const override{ return "Returns standard deviation of the dataset column"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            if (args.size() != 1){
                std::cout << "Usage: stddev <column>\n";
                return;
            }

            const std::string& col = args[0];

            if (!ctx.dataset.has_column(col)){
                std::cout << "Column not found: " << col << "\n";
                return;
            }

            const auto& ts = ctx.dataset.column(col);

            double result = core::Engine::stddev(ts);

            std::cout << "Standard Deviation(" << col << ") = " << result << "\n";
        }

    };

}
