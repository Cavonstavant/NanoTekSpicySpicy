/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** basic_gates
*/

#ifndef NANOTEKSPICE_BASIC_GATES_HPP
#define NANOTEKSPICE_BASIC_GATES_HPP

#include "../IComponent.hpp"


namespace nts {
    Tristate andGate(Tristate a, Tristate b);
    Tristate orGate(Tristate a, Tristate b);
    Tristate xorGate(Tristate a, Tristate b);
    Tristate notGate(Tristate a);
    Tristate nandGate(Tristate a, Tristate b);
    Tristate norGate(Tristate a, Tristate b);
    // Tristate sumGate(Tristate a, Tristate b, Tristate c);
    Tristate sumGateGetComputeWithCarry(Tristate a, Tristate b, Tristate c);
    Tristate sumGateGetCarry(Tristate a, Tristate b, Tristate c);
}// namespace nts


#endif//NANOTEKSPICE_BASIC_GATES_HPP
