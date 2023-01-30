#ifndef AUTOMATA_LINK_HPP
#define AUTOMATA_LINK_HPP

#include "state.hpp"
#include <vector>

namespace mm1
{
    namespace automata
    {
        class State;

        class Link
        {
        private:
            State *from;
            State *to;
            std::vector<int> symbols;
        public:
            Link(State *from, State *to, std::vector<int> symbols);
            ~Link();
            bool canPassed(int symbol);
            State *getFrom();
            State *getTo();
        };
    } // namespace automata
} // namespace mm1

#endif // AUTOMATA_LINK_HPP