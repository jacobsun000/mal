#include <iostream>
#include <string>
#include "linenoise.hpp"

std::string READ(std::string input)
{
    return input;
}

std::string EVAL(std::string input)
{
    return input;
}

std::string PRINT(std::string input)
{
    return input;
}

std::string rep(std::string input)
{
    return PRINT(EVAL(READ(input)));
}

int main()
{
    const auto historyPath = "history.txt";
    linenoise::LoadHistory(historyPath);

    std::string input;
    while (true)
    {
        std::cout << "user> ";
        bool quit = linenoise::Readline("user> ", input);
        if (quit)
            break;
        std::cout << rep(input) << std::endl;
        linenoise::AddHistory(input.c_str());
    }

    linenoise::SaveHistory(historyPath);

    return 0;
}