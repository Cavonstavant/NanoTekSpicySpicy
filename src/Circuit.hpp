/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP
#define NANOTEKSPICE_CIRCUIT_HPP

#include "Components/IOComponent.hpp"
#include "Exception.hpp"
#include "IComponent.hpp"

namespace nts {

    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() = default;

            void addComponent(std::string const &name, std::unique_ptr<IComponent> component);
            void addInputComponent(std::string const &name, std::unique_ptr<IComponent> inputComponent);
            void addOutputComponent(std::string const &name, std::unique_ptr<IComponent> outputComponent);
            void dump() const;
            void simulate(std::string const &inputs, std::string const &outputs);
            void setLink(std::string const &name, std::string const &pin, std::string const &otherName, std::string const &otherPin);

        private:
            IComponent &tryGetComponent(const std::string &name);
            std::map<std::string, std::reference_wrapper<IComponent>> _internalComponents;
            std::map<std::string, std::reference_wrapper<IComponent>> _inputComponents;
            std::map<std::string, std::reference_wrapper<IComponent>> _outputComponents;
    };

}// namespace nts

#endif//NANOTEKSPICE_CIRCUIT_HPP
