#include "automata.hpp"
#include <stack>
#include <iostream>
#include <string>

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

std::stack<int> decodeSymbol(int sym) {
    std::stack<int> pile;
    while (true) {
        pile.push(sym%10);
        if (sym < 10) {
            break;
        }
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
        currentState = currentState->canPassed(pile.top());
        pile.pop();
    }
    return currentState->isFinal();
}