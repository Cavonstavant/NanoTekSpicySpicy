/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#include <iostream>
#include "Circuit.hpp"

void nts::Circuit::addComponent(IComponent &component)
{
    _components.emplace_back(component);
}

void nts::Circuit::removeComponent(nts::IComponent &component)
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if ((it->get()) == component) {
            _components.erase(it);
            return;
        }
    }
}

void nts::Circuit::simulate(std::size_t tick)
{
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    return (Tristate::UNDEFINED);
}

void nts::Circuit::dump() const {
    std::cout << "{ " << std::endl;
    for (auto &component : _components)
        component.get().dump();
    std::cout << "}" << std::endl;
}
