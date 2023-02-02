#ifndef AUTOMATA_AUTOMATA_HPP
#define AUTOMATA_AUTOMATA_HPP

#include "state.hpp"
#include "link.hpp"
#include <vector>

namespace mm1
{
    namespace automata
    {
        class Automata
        {
        private:
            State * inputStates;
        public:
            Automata();
            ~Automata();
            void setInputState(State *state);
            bool canPassed(int symbol);
        };
    } // namespace automata
} // namespace mm1

#endif // AUTOMATA_AUTOMATA_HPP