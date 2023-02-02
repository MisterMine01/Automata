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
    for (int i = 0; i < 101; i+=5)
    {
        std::cout << i << ": " << automa.canPassed(i) << std::endl;
    }
}

void multipleCent() {
    Automata automa;
    State s0("s0");
    State s1("s1");
    State s2("s2", true);
    automa.setInputState(&s1);
    new Link(&s0, &s1, {0});
    new Link(&s1, &s2, {0});
    new Link(&s2, &s0, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    new Link(&s1, &s0, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    for (int i = 0; i < 501; i+=50)
    {
        std::cout << i << ": " << automa.canPassed(i) << std::endl;
    }
}

void count2numbersfollow() {
    Automata automa;
    State begin("begin");
    std::vector<State*> states;
    State end("end", true);
    for (int i = 0; i < 10; i++)
    {
        states.push_back(new State(std::to_string(i)));
    }
    for (size_t i = 0; i < states.size(); i++)
    {
        new Link(&begin, states[i], {(int)i});
        new Link(states[i], &end, {(int)i});
        for (size_t j = 0; j < states.size(); j++)
        {
            if (i == j)
                continue;
            new Link(states[i], states[j], {(int)j});
        }
    }
    automa.setInputState(&begin);
    for (int i = 0; i < 100; i++)
    {
        int r = rand();
        std::cout << r << ": " << automa.canPassed(r) << std::endl;
    }

}

int main()
{
    std::cout << "Multiple of 10" << std::endl;
    multipleDix();
    std::cout << "Multiple of 100" << std::endl;
    multipleCent();
    std::cout << "Count 2 numbers follow" << std::endl;
    count2numbersfollow();
    return 0;
}
