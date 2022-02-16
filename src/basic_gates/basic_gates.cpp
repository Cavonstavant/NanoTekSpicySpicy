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
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE && b == TRUE)
            return TRUE;
        return FALSE;
    }
    Tristate or_gate(Tristate a, Tristate b)
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE || b == TRUE)
            return TRUE;
        return FALSE;
    }
    Tristate xor_gate(Tristate a, Tristate b)
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE && b == FALSE || a == FALSE && b == TRUE)
            return TRUE;
        return FALSE;
    }
    Tristate not_gate(Tristate a)
    {
        if (a == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE)
            return FALSE;
        return TRUE;
    }
    Tristate nand_gate(Tristate a, Tristate b)
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        if (a == TRUE && b == TRUE)
            return FALSE;
        return TRUE;
    }
}