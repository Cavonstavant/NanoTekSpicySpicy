/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Exception.hpp"
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
    _states.emplace_back(std::make_pair(pin, nts::Tristate::UNDEFINED));
    other.setPin(otherPin, *this, pin);
}

void nts::AComponent::setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    LinkPair newPair = LinkPair(pin, otherPin, other);

    _links.emplace_back(newPair);
    _states.emplace_back(std::make_pair(pin, nts::Tristate::UNDEFINED));
}

/**
 * @brief get the state of a pin
 * @param pin
 * @return
 */
nts::Tristate nts::AComponent::pollState(size_t pin) const
{
    for (auto &state : _states) {
        if (std::get<size_t>(state) == pin)
            return (std::get<Tristate>(state));
    }
    return (nts::Tristate::UNDEFINED);
}

/**
 * @brief set the state of a given pin to the given value
 * @param pin
 * @param newState
 */
void nts::AComponent::setState(size_t pin, Tristate newState)
{
    for (auto &state : _states) {
        if (std::get<size_t>(state) == pin) {
            state = std::make_pair(pin, newState);
            return;
        }
    }
    throw nts::NtsException(std::string("pin: " + std::to_string(pin) + " not found"));
}

/**
 * @brief display infos about the component
 */
void nts::AComponent::dump() const {
    std::cout << _name << ": {" << std::endl;
    for (auto &it : _links)
        std::cout << "\t linked to " << it.get().component.getName() << "from pin: " << it.get().pin_other << " to pin: " << it.get().pin_self << std::endl;
    std::cout << "}" << std::endl;
}
