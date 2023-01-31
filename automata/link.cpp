#include "./link.hpp"
#include <stack>
#include <algorithm>
#include <vector>
#include <iostream>

mm1::automata::Link::Link(State *from, State *to, std::vector<int> symbols)
{
    this->from = from;
    this->from->addOLink(this);
    this->to = to;
    this->to->addILink(this);
    this->symbols = symbols;
}

mm1::automata::Link::~Link()
{
    std::cout << "Link deleted" << std::endl;
}

bool mm1::automata::Link::canPassed(int symbol)
{
    return (
        symbol == this->symbols[this->symbols.size() - 1] ||
        std::find(this->symbols.begin(), this->symbols.end(), symbol) != this->symbols.end());
}

mm1::automata::State *mm1::automata::Link::getFrom()
{
    return this->from;
}

mm1::automata::State *mm1::automata::Link::getTo()
{
    return this->to;
}