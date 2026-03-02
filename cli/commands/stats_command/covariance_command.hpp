#pragma once
#include "command.hpp"
#include "engine.hpp"

namespace cli{
    class CovarianceCommand : public Command{
    public:
        std::string name() const override{ return "cov"; }
        std::string help() const override{ return "Returns covariance of the two dataset columns"; }

        void execute(Context& ctx, std::vector<std::string>& args) override{
            if (args.size() != 2){
                std::cout << "Usage: covariance <column_X> <column_Y>\n";
                return;
            }

            const std::string& col_x = args[0], col_y = args[1];

            if (!ctx.dataset.has_column(col_x)){
                std::cout << "Column not found: " << col_x << "\n";
                return;
            }
            else if (!ctx.dataset.has_column(col_y)){
                std::cout << "Column not found: " << col_y << "\n";
                return;
            }

            const auto& tsx = ctx.dataset.column(col_x), tsy = ctx.dataset.column(col_y);

            double result = core::Engine::covariance(tsx, tsy);

            std::cout << "Covariance(" << col_x << ", " << col_y << ") = " << result << "\n";
        }

    };

}
