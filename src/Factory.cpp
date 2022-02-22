/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
}

nts::Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string& type)
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

std::unique_ptr<nts::IComponent> nts::Factory::create4001(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4013(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4040(const std::string &name) const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4008(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4017(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4069(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4094(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4514(const std::string &name) const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4801(const std::string &name) const {
    return nullptr;
}
