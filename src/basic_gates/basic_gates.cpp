/*
** EPITECH PROJECT, 2022
** nano_tek
** File description:
** basic_gates
*/

#include "../IComponent.hpp"

namespace nts {
    Tristate and_gate(Tristate a, Tristate b)
    {
        if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
            return nts::Tristate::UNDEFINED;
        if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
            return nts::Tristate::TRUE;
        return nts::Tristate::FALSE;
    }
    Tristate or_gate(Tristate a, Tristate b)
    {
        if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
            return nts::Tristate::UNDEFINED;
        if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
            return nts::Tristate::TRUE;
        return nts::Tristate::FALSE;
    }
    Tristate xor_gate(Tristate a, Tristate b)
    {
        if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
            return nts::Tristate::UNDEFINED;
        if (a == nts::Tristate::TRUE && b == nts::Tristate::FALSE || a == nts::Tristate::FALSE && b == nts::Tristate::TRUE)
            return nts::Tristate::TRUE;
        return nts::Tristate::FALSE;
    }
    Tristate not_gate(Tristate a)
    {
        if (a == nts::Tristate::UNDEFINED)
            return nts::Tristate::UNDEFINED;
        if (a == nts::Tristate::TRUE)
            return nts::Tristate::FALSE;
        return nts::Tristate::TRUE;
    }
    Tristate nand_gate(Tristate a, Tristate b)
    {
        if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
            return nts::Tristate::UNDEFINED;
        if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
            return nts::Tristate::FALSE;
        return nts::Tristate::TRUE;
    }
}