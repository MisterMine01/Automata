#include <iostream>
#include "automata/state.hpp"
#include "automata/link.hpp"
#include "automata/automata.hpp"
#include <vector>
#include <random>

using namespace mm1::automata;

void multipleDix()
{
    Automata automa;
    State s0("s0");
    automa.setInputState(&s0);
    State s1("s1", true);
    new Link(&s0, &s1, {0});
    new Link(&s1, &s0, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    for (int i = 0; i < 101; i++)
    {
        std::cout << i << ": " << automa.canPassed(i) << std::endl;
    }
}

int main()
{
    multipleDix();
    return 0;
}
