#pragma once
#include "command_registry.hpp"
#include "parser.hpp"
#include "data/dataset.hpp"

namespace cli{
    class REPL{
        public:
            REPL();
            void run();

        private:
            CommandRegistry registry_;
            Parser parser_;
            core::Dataset dataset_;
    };
}
