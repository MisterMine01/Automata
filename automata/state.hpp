#ifndef AUTOMATA_STATE_HPP
#define AUTOMATA_STATE_HPP

#include "link.hpp"
#include <vector>

namespace mm1
{
    namespace automata
    {
        class Link;

        class State
        {
        private:
            bool is_final = false;
            std::vector<Link *> in_links;
            std::vector<Link *> out_links;
        public:
            State(bool isFinal=false);
            ~State();
            void addILink(Link *link);
            void addOLink(Link *link);
            State canPassed(int symbol);
            bool isFinal();
        };
    } // namespace automata
} // namespace mm1

#endif // AUTOMATA_STATE_HPP