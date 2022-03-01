/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Circuit
*/

#ifndef NANOTEKSPICE_CIRCUIT_HPP
#define NANOTEKSPICE_CIRCUIT_HPP

#include "IComponent.hpp"
#include "Components/IOComponent.hpp"
#include "Exception.hpp"
#include <unordered_map>
#include <functional>
#include <memory>

namespace nts
{

    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() = default;

            void addComponent(std::string const &name, std::reference_wrapper<IComponent> component);
            void addInputComponent(std::string const &name, std::reference_wrapper<IComponent> inputComponent);
            void addOutputComponent(std::string const &name, std::reference_wrapper<IComponent> outputComponent);
            void dump() const;
            void simulate(std::string const &inputs, std::string const &outputs);
        private:
            std::unordered_map<std::string, std::reference_wrapper<IComponent>> _internalComponents;
            std::unordered_map<std::string, std::reference_wrapper<IComponent>> _inputComponents;
            std::unordered_map<std::string, std::reference_wrapper<IComponent>> _outputComponents;
    };

}

#endif //NANOTEKSPICE_CIRCUIT_HPP
