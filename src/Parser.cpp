/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
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

std::unique_ptr<nts::IComponent> nts::Parser::createComponent(const std::string& type)
{
    //TODO

//    if (type == "4001")
//        return create4001(type);
//    if (type == "4013")
//        return create4013(type);
//    if (type == "4040")
//        return create4040(type);
//    throw std::runtime_error("Unknown component");
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4001(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4013(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4040(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4008(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4011(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4017(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4030(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4069(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4071(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4081(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4094(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4514(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Parser::create4801(const std::string &name) const {
    return nullptr;
}
