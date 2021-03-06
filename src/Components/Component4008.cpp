/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4008
*/

#include "Component4008.hpp"

nts::Tristate nts::Component4008::compute(std::size_t pin)
{
    if (pin == 8 || pin == 16)
        throw nts::Exception::InvalidPinException("Reserved pin", pin);
    if (pin < 1 || pin > 16)
        throw nts::Exception::InvalidPinException("Pin not in range", pin);
    if (pin != 10 && pin != 11 && pin != 12 && pin != 13 && pin != 14)
        throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
    switch (pin) {
        case 10:
            return nts::sumGateGetComputeWithCarry(this->getState(6), this->getState(7), this->getState(9));
        case 11:
            return nts::sumGateGetComputeWithCarry(this->getState(4), this->getState(5), nts::sumGateGetCarry(this->getState(6), this->getState(7), this->getState(9)));
        case 12:
            return nts::sumGateGetComputeWithCarry(this->getState(2), this->getState(3), nts::sumGateGetCarry(this->getState(4), this->getState(5), nts::sumGateGetCarry(this->getState(6), this->getState(7), this->getState(9))));
        case 13:
            return nts::sumGateGetComputeWithCarry(this->getState(15), this->getState(1), nts::sumGateGetCarry(this->getState(2), this->getState(3), nts::sumGateGetCarry(this->getState(4), this->getState(5), nts::sumGateGetCarry(this->getState(6), this->getState(7), this->getState(9)))));
    }
    return nts::sumGateGetComputeWithCarry(this->getState(6), this->getState(7), this->getState(9));
}

//nts::Tristate nts::Component4008::compute(std::size_t pin) {
//    if (pin == 8 || pin == 16)
//        throw nts::Exception::InvalidPinException("Reserved pin", pin);
//    if (pin < 1 || pin > 16)
//        throw nts::Exception::InvalidPinException("Pin not in range", pin);
//    if (pin != 10 && pin != 11 && pin != 12 && pin != 13 && pin != 14)
//        throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
//// switch (pin) {
////     case 10:
////         // return (nts::sumGate)
////         // return this->getState(9) + this->getState(7) + this->getState(6);
////     case 11:
////         return (nts::norGate(this->getState(7), this->getState(6)));
////     case 12:
////         return (nts::norGate(this->getState(5), this->getState(4)));
////     case 13:
////         return (nts::norGate(this->getState(3), this->getState(2)));
////     case 14:
////         return (nts::norGate(this->getState(1), this->getState(0)));
//// }
//}
