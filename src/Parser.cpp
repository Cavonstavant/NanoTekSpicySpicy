/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Component.hpp"
#include <fstream>

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

void nts::Parser::fillCircuit(const std::string& file, Circuit &circuit)
{
    std::ifstream input(file);
    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    
}
