#include "automata.hpp"
#include <stack>


mm1::automata::Automata::Automata()
{
}

mm1::automata::Automata::~Automata()
{
}

void mm1::automata::Automata::setInputState(State *state)
{
    this->inputStates = state;
}

void mm1::automata::Automata::addState(State *state)
{
    this->states.push_back(state);
}

std::stack<int> decodeSymbol(int sym) {
    std::stack<int> pile;
    while (sym != 0) {
        pile.push(sym%10);
        sym /= 10;
    }
    return pile;
}

bool mm1::automata::Automata::canPassed(int symbol)
{
    State *currentState = this->inputStates;
    std::stack<int> pile = decodeSymbol(symbol);
    while (!pile.empty())
    {
        State tmp = currentState->canPassed(pile.top());
        currentState = &tmp;
        pile.pop();
    }
    return currentState->isFinal();
}