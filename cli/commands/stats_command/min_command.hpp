#pragma once
#include "command.hpp"
#include "engine.hpp"

namespace cli{
    class MinCommand : public Command{
    public:
        std::string name() const override{ return "min"; }
        std::string help() const override{ return "Returns minimum value from the dataset column"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            if (args.size() != 1){
                std::cout << "Usage: min <column>\n";
                return;
            }

            const std::string& col = args[0];

            if (!ctx.dataset.has_column(col)){
                std::cout << "Column not found: " << col << "\n";
                return;
            }

            const auto& ts = ctx.dataset.column(col);

            double result = core::Engine::min(ts);

            std::cout << "Min(" << col << ") = " << result << "\n";
        }

    };

}
