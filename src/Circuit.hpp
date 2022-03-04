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

        void addComponent(std::string const &name, IComponent &component);
        void addInputComponent(std::string const &name, IComponent &inputComponent);
        void addOutputComponent(std::string const &name, IComponent &outputComponent);
        void dump() const;
        void simulate(size_t tick=1);

    private:
        std::map<std::string, std::reference_wrapper<IComponent>> _internalComponents;
        std::map<std::string, std::reference_wrapper<IComponent>> _inputComponents;
        std::map<std::string, std::reference_wrapper<IComponent>> _outputComponents;
    };
}// namespace nts

#endif//NANOTEKSPICE_CIRCUIT_HPP
