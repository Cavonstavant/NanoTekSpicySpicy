/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4001
*/

#ifndef NANOTEKSPICE_COMPONENT4001_HPP
#define NANOTEKSPICE_COMPONENT4001_HPP

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"

namespace nts {
    class Component4001 : public AComponent {
        public:
        Component4001() = delete;
        explicit Component4001(const std::string &name) : AComponent(name){};
        Component4001(const Component4001 &other) = delete;
        Component4001 &operator=(const Component4001 &other) = delete;
        /**
    * @brief Compute the state of the pin
    * @param pin
    * @return the state of the pin
    * @throw nts::Exception::InvalidPinException if the pin is not valid
    */
        nts::Tristate compute(std::size_t pin) final {
            if (pin == 7 || pin == 14)
                throw nts::Exception::InvalidPinException("Reserved pin", pin);
            if ((pin < 1 || pin > 14))
                throw nts::Exception::InvalidPinException("Pin not in rage", pin);
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
        ~Component4001() override = default;

        protected:
        private:
    };
}// namespace nts

#endif /* !NANOTEKSPICE_COMPONENT4001_HPP */
