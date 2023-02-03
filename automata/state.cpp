#include "./state.hpp"
#include <iostream>

mm1::automata::State::State(std::string name, bool isFinal)
{
    this->is_final = isFinal;
    this->name = name;
}

mm1::automata::State::~State()
{
}

void mm1::automata::State::addILink(Link *link)
{
    this->in_links.push_back(link);
}

void mm1::automata::State::addOLink(Link *link)
{
    this->out_links.push_back(link);
}

mm1::automata::State* mm1::automata::State::canPassed(int symbol)
{
    for (int i = 0; i < (this->out_links.size()); i++)
    {
        mm1::automata::Link *l = this->out_links.at(i);    
        if (l->canPassed(symbol))
        {
            return l->getTo();
        }
    }
    return this;
}

bool mm1::automata::State::isFinal()
{
    return this->is_final;
}