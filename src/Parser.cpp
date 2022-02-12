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

void nts::Parser::fillCircuit(std::string file, Circuit &circuit)
{
    std::ifstream input(file);
    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    
}

std::unique_ptr<nts::IComponent> nts::Parser::createComponent(const std::string& type)
{
    if (type == "4001")
        return create4001();
    if (type == "4013")
        return create4013();
    if (type == "4040")
        return create4040();
    throw std::runtime_error("Unknown component");
}

std::unique_ptr<nts::IComponent> nts::Parser::create4001() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4013() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4040() const
{
    return nullptr;
}
