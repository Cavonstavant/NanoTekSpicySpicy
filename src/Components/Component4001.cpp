/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component2716
*/

#include <string>
#include "Component4001.hpp"

nts::Tristate nts::Component4001::compute(std::size_t pin)
{
    if (pin == 7 || pin == 14)
        throw nts::Exception::InvalidPinException("Reserved pin", pin);
    if ((pin < 1 || pin > 14))
        throw nts::Exception::InvalidPinException("Pin not in range", pin);
    if (pin != 3 && pin != 4 && pin != 10 && pin != 11)
        throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
    switch (pin) {// NOLINT(hicpp-multiway-paths-covered)
        case 3:
            return (nts::norGate(this->getState(1), this->getState(2)));
        case 4:
            return (nts::norGate(this->getState(5), this->getState(6)));
        case 10:
            return (nts::norGate(this->getState(9), this->getState(8)));
    }
    return (nts::norGate(this->getState(13), this->getState(12)));
}