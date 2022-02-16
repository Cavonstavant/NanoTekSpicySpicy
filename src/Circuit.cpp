/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

void nts::Circuit::addComponent(std::reference_wrapper<IComponent> component)
{
    _components.push_back(component);
}

void nts::Circuit::removeComponent(std::reference_wrapper<nts::IComponent> component)
{
    _components.remove(component);
}

void nts::Circuit::simulate(std::size_t tick)
{
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    return (Tristate::UNDEFINED);
}
