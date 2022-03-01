/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"

/**
 * @brief add a component to the circuit
 * @param name
 * @param component
 * @throw nts::Exception::InvalidComponentException if the component is an IOComponent
 */
void nts::Circuit::addComponent(const std::string &name,
                                std::reference_wrapper<IComponent> component) {
    if (dynamic_cast<std::unique_ptr<nts::IOComponent> &>(component.get()) != nullptr)
        throw nts::Exception::InvalidComponentException("Can't add an IO component as an internal component");
    _internalComponents[name] = component;
}

/**
 * @brief add an input to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addInputComponent(const std::string &name,
                                     std::reference_wrapper<nts::IComponent> inputComponent) {
    if (dynamic_cast<std::unique_ptr<nts::IOComponent> &>(inputComponent.get()) == nullptr)
        throw nts::Exception::InvalidComponentException("Can't add an internal component as an input component");
    _inputComponents[name] = inputComponent;
}

/**
 * @brief add an output to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addOutputComponent(const std::string &name,
                                      std::reference_wrapper<nts::IComponent> outputComponent) {
    if (dynamic_cast<std::unique_ptr<nts::IOComponent> &>(outputComponent.get()) == nullptr)
        throw nts::Exception::InvalidComponentException("Can't add an internal component as an output component");
    _outputComponents[name] = outputComponent;
}

/**
 * @brief dump the configuration of the circuit
 */
void nts::Circuit::dump() const {
    for (auto &component: _internalComponents) {
        std::get<std::reference_wrapper<IComponent>>(component).get().dump();
    }
}

/**
 * @brief simulate the circuit
 * @param inputs
 * @param outputs
 * This method assumes that all the link are set
 */
void nts::Circuit::simulate(const std::string &inputs, const std::string &outputs) {
}
