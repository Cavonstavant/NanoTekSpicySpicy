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
        nts::Tristate compute(std::size_t pin) final;
        ~Component4011() override = default;
        protected:
        private:
    };
};// namespace nts

#endif /* !COMPONENT4011_HPP_ */
