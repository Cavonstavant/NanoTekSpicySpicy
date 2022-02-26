/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Components/IOComponent.hpp"

nts::Factory::Factory()
{
    _factoryMap["input"] = std::bind(&nts::Factory::createInput, this);
    _factoryMap["output"] = std::bind(&nts::Factory::createOutput, this);
    _factoryMap["2716"] = std::bind(&nts::Factory::create2716, this);
    _factoryMap["4001"] = std::bind(&nts::Factory::create4001, this);
    _factoryMap["4008"] = std::bind(&nts::Factory::create4008, this);
    _factoryMap["4011"] = std::bind(&nts::Factory::create4011, this);
    _factoryMap["4013"] = std::bind(&nts::Factory::create4013, this);
    _factoryMap["4017"] = std::bind(&nts::Factory::create4017, this);
    _factoryMap["4030"] = std::bind(&nts::Factory::create4030, this);
    _factoryMap["4040"] = std::bind(&nts::Factory::create4040, this);
    _factoryMap["4069"] = std::bind(&nts::Factory::create4069, this);
    _factoryMap["4071"] = std::bind(&nts::Factory::create4071, this);
    _factoryMap["4081"] = std::bind(&nts::Factory::create4081, this);
    _factoryMap["4094"] = std::bind(&nts::Factory::create4094, this);
    _factoryMap["4514"] = std::bind(&nts::Factory::create4514, this);
    _factoryMap["4801"] = std::bind(&nts::Factory::create4801, this);
}

nts::Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string& type)
{
    try {
        return _factoryMap[type]();
    } catch (const std::exception) {
        throw nts::Exception::InvalidComponentException("Invalid component type");
    }
}

std::unique_ptr<nts::IComponent> nts::Factory::createInput() const
{
    IOComponent component;
    component.setType(nts::IOType::INPUT);
    return std::make_unique<IOComponent>(component);
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput() const
{
    IOComponent component;
    component.setType(nts::IOType::OUTPUT);
    return std::make_unique<IOComponent>(component);
}

std::unique_ptr<nts::IComponent> nts::Factory::create2716() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4001() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4013() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4040() const
{
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4008() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4017() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4069() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4094() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4514() const {
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4801() const {
    return nullptr;
}
