/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include <iostream>


nts::AComponent::AComponent(const std::string& name)
{
    this->_name = name;
}

void nts::AComponent::setName(const std::string &name) {
    this->_name = name;
}

std::string nts::AComponent::getName() const {
    return (this->_name);
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    LinkPair newPair = LinkPair(pin, otherPin, other);

    _links.emplace_back(newPair);
    other.setPin(otherPin, *this, pin);
}

void nts::AComponent::setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    LinkPair newPair = LinkPair(pin, otherPin, other);

    _links.emplace_back(newPair);
}

nts::Tristate nts::AComponent::pollState(size_t pin) const
{
    return (_states[pin]);
}

void nts::AComponent::setState(size_t pin, Tristate state)
{
    _states[pin] = state;
}

void nts::AComponent::dump() const {
    std::cout << _name << ": {" << std::endl;
    for (auto &it : _links)
        std::cout << "\t linked to " << it.get().component.getName() << "from pin: " << it.get().pin_other << " to pin: " << it.get().pin_self << std::endl;
    std::cout << "}" << std::endl;
}
