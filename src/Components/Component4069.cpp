/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4069
*/

#include "Component4069.hpp"

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    if (pin == 7 || pin == 14)
        throw nts::Exception::InvalidPinException("Reserved pin", pin);
    if ((pin < 1 || pin > 14))
        throw nts::Exception::InvalidPinException("Pin not in range", pin);
    if (pin != 2 && pin != 4 && pin != 6 && pin != 8 && pin != 10 && pin != 12)
        throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
    switch (pin) {
        case 2:
            return (nts::notGate(this->getState(1)));
        case 4:
            return (nts::notGate(this->getState(3)));
        case 6:
            return (nts::notGate(this->getState(5)));
        case 8:
            return (nts::notGate(this->getState(9)));
        case 10:
            return (nts::notGate(this->getState(11)));
    }
    return (nts::notGate(this->getState(13)));
}