/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** IOComponent
*/

#include "IOComponent.hpp"

nts::IOComponent::IOComponent(nts::IOType type)
    : _type(type) {}

nts::Tristate nts::IOComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return std::get<nts::Tristate>(_states[0]);
    throw nts::Exception::InvalidPinException("Invalid pin", 1);
}

nts::IOType nts::IOComponent::getType() const
{
    return _type;
}

void nts::IOComponent::setType(nts::IOType type)
{
    _type = type;
}
