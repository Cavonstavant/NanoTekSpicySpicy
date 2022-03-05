/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Exception.hpp"
#include <iostream>
#include <sstream>

/**
 * @brief add a component to the circuit
 * @param name
 * @param component
 * @throw nts::Exception::InvalidComponentException if the component is an IOComponent
 */

void nts::Circuit::addComponent(const std::string &name,
                                std::unique_ptr<IComponent> component)
{
    // _internalComponents.emplace(name, std::move(component));
    // _internalComponents[name] = component;
    //    auto *ioComponent = dynamic_cast<nts::IOComponent *>(component);
    //    if (ioComponent)
    //        throw nts::Exception::InvalidComponentException("Can't add an IO component as an internal component");
    //    _internalComponents[name] = std::ref(component);
}

/**
 * @brief add an input to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addInputComponent(const std::string &name,
                                     std::unique_ptr<IComponent> inputComponent)
{
    // auto *ioComponent = dynamic_cast<nts::IOComponent *>(&inputComponent);
    // if (ioComponent != nullptr)
    //     throw nts::Exception::InvalidComponentException("Can't add an internal component as an input component");
    //    _inputComponents[name] = inputComponent;
}

/**
 * @brief add an output to the circuit
 * @param name
 * @param inputComponent
 * @throw nts::Exception::InvalidComponentException if the component is not an IOComponent
 */
void nts::Circuit::addOutputComponent(const std::string &name,
                                      std::unique_ptr<IComponent> outputComponent)
{
    // auto *ioComponent = dynamic_cast<nts::IOComponent *>(&outputComponent);
    // if (dynamic_cast<std::unique_ptr<nts::IOComponent> &>(outputComponent) == nullptr)
    //     throw nts::Exception::InvalidComponentException("Can't add an internal component as an output component");
    //    _outputComponents[name] = outputComponent;
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

nts::IComponent &nts::Circuit::tryGetComponent(const std::string &name)
{
    if (_internalComponents.find(name) != _internalComponents.end())
        return _internalComponents.at(name);
    else if (_inputComponents.find(name) != _inputComponents.end())
        return _inputComponents.at(name);
    else if (_outputComponents.find(name) != _outputComponents.end())
        return _outputComponents.at(name);
    else
        throw nts::Exception::InvalidComponentException("Component not found");
    // try {
    //     return _inputComponents.at(name);
    // } catch (std::exception &) {
    //     try {
    //         return _outputComponents.at(name);
    //     } catch (std::exception &e) {
    //         try {
    //             return _internalComponents.at(name);
    //         } catch (std::exception &) {
    //             throw Exception::InvalidComponentException("Can't find the component");
    //         }
    //     }
    // }
}

static size_t strtosize(const std::string &str)
{
    size_t size = 0;
    std::stringstream ss;
    ss << str;
    ss >> size;
    return size;
}

void nts::Circuit::setLink(const std::string &name, const std::string &pin,
                           const std::string &otherName, const std::string &otherPin)
{
    IComponent &component = tryGetComponent(name);
    IComponent &otherComponent = tryGetComponent(otherName);

    component.setLink(strtosize(pin), otherComponent, strtosize(otherPin));
}
