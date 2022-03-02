/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
#define COMPONENT4008_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"

namespace nts {
class Component4008 : public AComponent {
public:
    Component4008() = delete;
    ~Component4008() override = default;
    explicit Component4008(const std::string &name) : AComponent(name) {};
    Component4008(const Component4008 &other) = delete;
    Component4008 &operator=(const Component4008 &other) = delete;
    nts::Tristate compute(std::size_t pin) final {
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
    }

protected:
private:
};
}// namespace nts

#endif /* !COMPONENT4008_HPP_ */
