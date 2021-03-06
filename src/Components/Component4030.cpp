/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4030
*/

#include "Component4030.hpp"

nts::Tristate nts::Component4030::compute(std::size_t pin)
{
    if (pin == 7 || pin == 14)
        throw nts::Exception::InvalidPinException("Reserved pin", pin);
    if ((pin < 1 || pin > 14))
        throw nts::Exception::InvalidPinException("Pin not in range", pin);
    if (pin != 3 && pin != 4 && pin != 10 && pin != 11)
        throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
    switch (pin) {
        case 3:
            return (nts::xorGate(this->getState(1), this->getState(2)));
        case 4:
            return (nts::xorGate(this->getState(5), this->getState(6)));
        case 10:
            return (nts::xorGate(this->getState(9), this->getState(8)));
    }
    return (nts::xorGate(this->getState(13), this->getState(12)));
}
