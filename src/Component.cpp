/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Component
*/

#include "Component.hpp"

nts::Component::Component(const std::string& name)
{
    this->_name = name;
}

void nts::Component::setName(const std::string &name) {
    this->_name = name;
}

std::string nts::Component::getName() const {
    return (this->_name);
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // _links.push_back(std::make_pair(pin, otherPin));
    // _links.push_back(other, std::make_pair(pin, otherPin))
    // _links[pin] = other;
    // std::pair<size_t, size_t> sizes = std::make_pair(pin, otherPin);
    // std::pair<IComponent &, std::pair<size_t, size_t>> link = std::make_pair(other, sizes);
    // _links.push_back(std::make_pair(other, std::make_pair(pin, otherPin)));
//    _links.emplace_back(&other, std::make_pair(pin, otherPin));
    other.setPin(otherPin, *this, pin);
}

void nts::Component::setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    _links.emplace_back(&other, std::make_pair(pin, otherPin));
}

nts::Tristate nts::Component::pollState(size_t pin) const
{
    return (_states[pin]);
}

void nts::Component::setState(size_t pin, Tristate state)
{
    _states[pin] = state;
}
