/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#include <iostream>
#include "Exception.hpp"
#include "Circuit.hpp"

/**
 * @brief add a new component to the circuit
 * @param component
 */
void nts::Circuit::addComponent(IComponent &component)
{
    _components.emplace_back(component);
}

/**
 * @brief remove a component from the circuit
 * @param component
 */
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
    for (auto &component : _components) {
        component.get().simulate(tick);
    }
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{

    return (Tristate::UNDEFINED);
}

/**
 * @brief display the circuit infos
 */
void nts::Circuit::dump() const
{
    std::cout << "{ " << std::endl;
    for (auto &component : _components)
        component.get().dump();
    std::cout << "}" << std::endl;
}

/**
 * @brief will set a link between the circuit at and a component
 * @param pin a pin of the circuit
 * @param other the component to connect to
 * @param otherPin the pin of the component
 * @warning pin and otherPin must be valid
 * @warning other must not be an IOComponent, use addInput or addOutput instead
 * @throw nts::Exception::InvalidPinException if pin or otherPin are invalid
 * @throw nts::Exception::InvalidTypeException if the component is not of a valid type
 */
void nts::Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (static_cast<IOComponent>(other).getType() == "IOComponent")
        throw nts::Exception::InvalidTypeException("other must not be an IOComponent");
}
