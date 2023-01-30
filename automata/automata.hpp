#ifndef AUTOMATA_AUTOMATA_HPP
#define AUTOMATA_AUTOMATA_HPP

#include "./state.hpp"
#include "./link.hpp"

namespace mm1
{
    namespace automata
    {
        class Automata
        {
        public:
            Automata();
            ~Automata();
            void addInputState(State *state);
            void addState(State *state);
            bool canPassed(int symbol);
        };
    } // namespace automata
} // namespace mm1

#endif // AUTOMATA_AUTOMATA_HPP