/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Exception.hpp"
#include <iostream>

nts::AComponent::AComponent(const std::string &name) { this->_name = name; }

void nts::AComponent::setName(const std::string &name) { this->_name = name; }

std::string nts::AComponent::getName() const { return (this->_name); }

bool nts::AComponent::operator==(const nts::IComponent &other) const {
  auto &other_component =
      dynamic_cast<AComponent &>(const_cast<nts::IComponent &>(other));
  return (this->_name == other_component.getName());
}

/**
 * @brief
 * @param pin
 * @param other
 * @param otherPin
 */
void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
                              std::size_t otherPin) {
  LinkPair newPair = LinkPair(pin, otherPin, other);

  _links.emplace_back(newPair);
  _states.emplace_back(std::make_pair(pin, nts::Tristate::UNDEFINED));
  other.setPin(otherPin, *this, pin);
}

void nts::AComponent::setPin(std::size_t pin, nts::IComponent &other,
                             std::size_t otherPin) {
  LinkPair newPair = LinkPair(pin, otherPin, other);

  _links.emplace_back(newPair);
  _states.emplace_back(std::make_pair(pin, nts::Tristate::UNDEFINED));
}

/**
 * @brief get the state of a pin
 * @param pin
 * @return the state of the pin
 * @throw nts::Exception::UnknownPinException if the pin is not found
 */
nts::Tristate nts::AComponent::pollState(size_t pin) const {
  for (auto &state : _states) {
    if (std::get<size_t>(state) == pin)
      return (std::get<Tristate>(state));
  }
  throw nts::Exception::UnknownPinException(
      std::string("pin: " + std::to_string(pin) + " not found"), pin);
}

/**
 * @brief set the state of a given pin to the given value
 * @param pin
 * @param newState
 * @throw nts::Exception::UnknownPinException if the pin is not found
 */
void nts::AComponent::setState(size_t pin, Tristate newState) {
  for (auto &state : _states) {
    if (std::get<size_t>(state) == pin) {
      state = std::make_pair(pin, newState);
      return;
    }
  }
  throw nts::Exception::UnknownPinException(
      std::string("pin: " + std::to_string(pin) + " not found"), pin);
}

/**
 * @brief display infos about the component
 */
void nts::AComponent::dump() const {
  std::cout << _name << ": {" << std::endl;
  for (auto &it : _links)
    std::cout << "\t linked to " << it.get().component.getName()
              << "from pin: " << it.get().pin_other
              << " to pin: " << it.get().pin_self << std::endl;
  std::cout << "}" << std::endl;
}

nts::Tristate nts::AComponent::getState(size_t pin) const {
  for (auto &state : _states) {
    if (std::get<size_t>(state) == pin)
      return (std::get<Tristate>(state));
  }
  throw nts::Exception::UnknownPinException(
      std::string("pin: " + std::to_string(pin) + " not found"), pin);
}

/**
 * @brief Can't simulate an abstract component (should be implemented in the
 * child class)
 * @param tick
 * @throw nts::Exception::InvalidComponentException
 */
void nts::AComponent::simulate(std::size_t tick) {
  throw nts::Exception::InvalidComponentException(
      "simulate is not implemented");
}

/**
 * @brief Can't compute an abstract component (should be implemented in the
 * child class)
 * @param pin
 * @return the state of the pin
 * @throw nts::Exception::InvalidComponentException
 */
nts::Tristate nts::AComponent::compute(std::size_t pin) {
  throw nts::Exception::InvalidComponentException("compute is not implemented");
}