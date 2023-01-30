#include "./state.hpp"

mm1::automata::State::State(bool isFinal)
{
    this->is_final = isFinal;
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

bool mm1::automata::State::isFinal()
{
    return this->is_final;
}