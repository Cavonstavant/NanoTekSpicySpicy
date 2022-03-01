/*
** EPITECH PROJECT, 2022
** nano_tek
** File description:
** basic_gates
*/

#include "../IComponent.hpp"

namespace nts {
Tristate andGate(Tristate a, Tristate b) {
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate orGate(Tristate a, Tristate b) {
    if (a == nts::Tristate::UNDEFINED)
        return b;
    if (b == nts::Tristate::UNDEFINED)
        return a;
    if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate xorGate(Tristate a, Tristate b) {
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE && b == nts::Tristate::FALSE || a == nts::Tristate::FALSE && b == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}
Tristate notGate(Tristate a) {
    if (a == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (a == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}
Tristate nandGate(Tristate a, Tristate b) {
    return (notGate(andGate(a, b)));
}
Tristate norGate(Tristate a, Tristate b) {
    return (notGate(orGate(a, b)));
}
}// namespace nts
