/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Component
*/

#include "Component.hpp"

nts::Component::Component()
{
}

nts::Component::~Component()
{
}

nts::Tristate nts::Component::compute(std::size_t pi)
{
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
