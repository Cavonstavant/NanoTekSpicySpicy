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

nts::Component::Component(const nts::Component &other) {
    this->_name = other._name;
    this->_links = other._links;
    this->_states = other._states;
}

nts::Component &nts::Component::operator=(const nts::Component &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_links = other._links;
        this->_states = other._states;
    }
    return (*this);
}

void nts::Component::setName(const std::string &name) {
    this->_name = name;
}

std::string nts::Component::getName() const {
    return (this->_name);
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = other;
    other.setPin(otherPin, *this);
}

void nts::Component::setPin(std::size_t pin, nts::IComponent &other)
{
    _links[pin] = other;
}
