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
                                IComponent &component)
{
    auto *ioComponent = dynamic_cast<nts::IOComponent *>(&component);
    if (ioComponent)
        throw nts::Exception::InvalidComponentException("Can't add an IO component as an internal component");
    //    std::reference_wrapper<IComponent> cmp = component;
    //    std::string str = "toto";
    //    std::reference_wrapper<IComponent> ref = _internalComponents.at(str);
    //    ref = cmp;
    //    _internalComponents["toto"] = cmp;
    _internalComponents.emplace(name, component);
}

/**
 * @brief add an input to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addInputComponent(const std::string &name,
                                     IComponent &inputComponent)
{
    auto *ioComponent = dynamic_cast<nts::IOComponent *>(&inputComponent);
    if (ioComponent != nullptr)
        throw nts::Exception::InvalidComponentException("Can't add an internal component as an input component");
    _inputComponents.emplace(inputComponent);
}

/**
 * @brief add an output to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addOutputComponent(const std::string &name,
                                      IComponent &outputComponent)
{
    auto *ioComponent = dynamic_cast<nts::IOComponent *>(&outputComponent);
    if (dynamic_cast<std::unique_ptr<nts::IOComponent> &>(outputComponent) == nullptr)
        throw nts::Exception::InvalidComponentException("Can't add an internal component as an output component");
    _outputComponents.emplace(outputComponent);
}

/**
 * @brief dump the configuration of the circuit
 */
void nts::Circuit::dump() const
{
    //    for (auto &component: _internalComponents) {
    //        std::get<std::reference_wrapper<IComponent>>(component).get().dump();
    //    }
}

/**
 * @brief simulate the circuit
 * @param inputs
 * @param outputs
 * This method assumes that all the link are set
 */
void nts::Circuit::simulate(const std::string &inputs, const std::string &outputs)
{
}
