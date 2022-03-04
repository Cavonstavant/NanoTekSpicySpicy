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
            nts::Tristate compute(std::size_t pin) final;

        protected:
        private:
    };
}// namespace nts

#endif /* !COMPONENT4008_HPP_ */
