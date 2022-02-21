/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

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
    // _links.push_back(std::make_pair(pin, otherPin));
    // _links.push_back(other, std::make_pair(pin, otherPin))
    // _links[pin] = other;
    // std::pair<size_t, size_t> sizes = std::make_pair(pin, otherPin);
    // std::pair<IComponent &, std::pair<size_t, size_t>> link = std::make_pair(other, sizes);
    // _links.push_back(std::make_pair(other, std::make_pair(pin, otherPin)));
//    _links.emplace_back(&other, std::make_pair(pin, otherPin));
    other.setPin(otherPin, *this, pin);
}

void nts::AComponent::setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
//    _links.emplace_back(&other, std::make_pair(pin, otherPin));
}

nts::Tristate nts::AComponent::pollState(size_t pin) const
{
    return (_states[pin]);
}

void nts::AComponent::setState(size_t pin, Tristate state)
{
    _states[pin] = state;
}
