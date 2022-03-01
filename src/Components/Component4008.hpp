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
            explicit Component4008(const std::string &name) : AComponent(name){};
            Component4008(const Component4008 &other) = delete;
            Component4008 &operator=(const Component4008 &other) = delete;
            nts::Tristate compute(std::size_t pin) final {
                if (pin == 8 || pin == 16)
                    throw nts::Exception::InvalidPinException("Reserved pin", pin);
                if (pin < 1 || pin > 16)
                    throw nts::Exception::InvalidPinException("Pin not in range", pin);
                if (pin != 10 && pin != 11 && pin != 12 && pin != 13 && pin != 14)
                    throw nts::Exception::InvalidPinException("Trying to compute the state of an input pin", pin);
                // switch (pin) {
                //     case 10:
                //         // return (nts::sumGate)
                //         // return this->getState(9) + this->getState(7) + this->getState(6);
                //     case 11:
                //         return (nts::norGate(this->getState(7), this->getState(6)));
                //     case 12:
                //         return (nts::norGate(this->getState(5), this->getState(4)));
                //     case 13:
                //         return (nts::norGate(this->getState(3), this->getState(2)));
                //     case 14:
                //         return (nts::norGate(this->getState(1), this->getState(0)));
                // }
            }

        protected:
        private:
    };
}

#endif /* !COMPONENT4008_HPP_ */
