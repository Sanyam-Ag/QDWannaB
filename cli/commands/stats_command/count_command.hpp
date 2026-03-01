#pragma once
#include "command.hpp"
#include "engine.hpp"

namespace cli{
    class CountCommand : public Command{
    public:
        std::string name() const override{ return "count"; }
        std::string help() const override{ return "Returns number of values in the dataset column"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            if (args.size() != 1){
                std::cout << "Usage: count <column>\n";
                return;
            }

            const std::string& col = args[0];

            if (!ctx.dataset.has_column(col)){
                std::cout << "Column not found: " << col << "\n";
                return;
            }

            const auto& ts = ctx.dataset.column(col);

            double result = core::Engine::count(ts);

            std::cout << "Count(" << col << ") = " << result << "\n";
        }

    };

}
