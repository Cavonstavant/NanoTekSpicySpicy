/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"


namespace nts {
    class Component4011 : public AComponent {
        public:
        Component4011() = delete;
        explicit Component4011(const std::string &name) : AComponent(name){};
        Component4011(const Component4011 &other) = delete;
        Component4011 &operator=(const Component4011 &other) = delete;
        nts::Tristate compute(std::size_t pin) final {
            if (pin == 7 || pin == 14)
                throw nts::Exception::InvalidPinException("Reserved pin", pin);
            if ((pin < 1 || pin > 14))
                throw nts::Exception::InvalidPinException("Pin not in range", pin);
            if (pin != 3 && pin != 4 && pin != 10 && pin != 11)
                throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
            switch (pin) {
                case 3:
                    return (nts::nandGate(this->getState(1), this->getState(2)));
                case 4:
                    return (nts::nandGate(this->getState(5), this->getState(6)));
                case 10:
                    return (nts::nandGate(this->getState(9), this->getState(8)));
            }
            return (nts::nandGate(this->getState(13), this->getState(12)));
        }
        ~Component4011() override = default;

        protected:
        private:
    };
};// namespace nts

#endif /* !COMPONENT4011_HPP_ */
