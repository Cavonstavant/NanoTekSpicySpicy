/*
** EPITECH PROJECT, 2022
** nano_tek
** File description:
** basic_gates
*/

#include "../IComponent.hpp"

namespace nts {
Tristate andGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate orGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::UNDEFINED)
        return b;
    if (b == nts::Tristate::UNDEFINED)
        return a;
    if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate xorGate(Tristate a, Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE && b == nts::Tristate::FALSE || a == nts::Tristate::FALSE && b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate notGate(Tristate a)
{
    if (a == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}
Tristate nandGate(Tristate a, Tristate b)
{
    return (notGate(andGate(a, b)));
}
Tristate norGate(Tristate a, Tristate b)
{
    return (notGate(orGate(a, b)));
}
// Tristate sumGate(Tristate a, Tristate b, Tristate c)
// {
//     if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED || c == nts::Tristate::UNDEFINED)
//         return nts::Tristate::UNDEFINED;
//     int zero = 0;
//     int one = 0;
//     if (a == nts::Tristate::TRUE)
//         one++;
//     if (b == nts::Tristate::TRUE)
//         one++;
//     if (c == nts::Tristate::TRUE)
//         one++;
//     if (one == 2)
//         return nts::Tristate::TRUE;
//     return nts::Tristate::FALSE;
// }
Tristate sumGateGetCarry(Tristate a, Tristate b, Tristate c)
{
    return xorGate(xorGate(a, b), c);
}

Tristate sumGateGetComputeWithCarry(Tristate a, Tristate b, Tristate c)
{
    return orGate(andGate(a, b), andGate(xorGate(a, b), c));
}
}// namespace nts
