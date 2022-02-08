/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::addComponent(IComponent& component)
{
    _components.push_back(component);
}

void nts::Circuit::removeComponent(IComponent& component)
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
