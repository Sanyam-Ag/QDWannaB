#pragma once
#include "command_registry.hpp"
#include "parser.hpp"

namespace cli{
    class REPL{
        public:
            REPL();
            void run();

        private:
            CommandRegistry registry_;
            Parser parser_;
    };
}
