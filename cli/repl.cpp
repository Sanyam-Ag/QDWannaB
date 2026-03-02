#include "repl.hpp"
#include "load_command.hpp"
#include "exit_command.hpp"
#include "help_command.hpp"
#include "mean_command.hpp"
#include "variance_command.hpp"
#include "stddev_command.hpp"
#include "min_command.hpp"
#include "max_command.hpp"
#include "count_command.hpp"
#include "covariance_command.hpp"
#include "correlation_command.hpp"
#include "timeseries.hpp"
#include <iostream>
#include <sstream>

namespace cli{
    REPL::REPL(){
        registry_.register_command(std::make_unique<LoadCommand>());
        registry_.register_command(std::make_unique<ExitCommand>());
        registry_.register_command(std::make_unique<HelpCommand>(registry_));
        registry_.register_command(std::make_unique<MeanCommand>());
        registry_.register_command(std::make_unique<VarianceCommand>());
        registry_.register_command(std::make_unique<StddevCommand>());
        registry_.register_command(std::make_unique<MinCommand>());
        registry_.register_command(std::make_unique<MaxCommand>());
        registry_.register_command(std::make_unique<CountCommand>());
        registry_.register_command(std::make_unique<CovarianceCommand>());
        registry_.register_command(std::make_unique<CorrelationCommand>());

        //TimeSeries ts1({1.0, 2.0, 3.0});
        //TimeSeries ts2({10.0, 20.0, 30.0});

        //dataset_.add_column("prices.close", ts1);
        //dataset_.add_column("prices.volume", ts2);

    }

    void REPL::run(){
        std::string line;

        while (true){
            std::cout << "> ";

            if (!std::getline(std::cin, line)){
                break;
            }

            auto parsed = parser_.parse(line);
            if (parsed.command.empty()){
                continue;
            }

            try{
                Command* cmd = registry_.get(parsed.command);
                if (!cmd){
                    std::cout << "Unknown command\n";
                    continue;
                }

                cmd->execute(context_, parsed.args);
            }
            catch (const std::runtime_error& e){
                if (std::string(e.what()) == "exit"){
                    break;
                }
                std::cout << "Error: " << e.what() << "\n";
            }
            catch (const std::exception& e){
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }
}
