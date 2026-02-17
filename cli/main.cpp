#include "engine.hpp"
#include "repl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    /*
    if (argc < 3) {
        std::cerr << "Usage: tsengine <mean|variance> <file.csv>\n";
        return 1;
    }

    Engine engine;
    TimeSeries ts = engine.load(argv[2], "");

        vector<double> val = ts.values();
        for(auto x:val) std::cout << x << ", ";
        std::cout << '\n';
    

    if (std::string(argv[1]) == "mean") {
        std::cout << engine.mean(ts) << "\n";
    } else if (std::string(argv[1]) == "variance") {
        std::cout << engine.variance(ts) << "\n";
    } else {
        std::cerr << "Unknown command\n";
        return 1;
    }
    */

    cli::REPL repl;
    repl.run();
    return 0;
}
