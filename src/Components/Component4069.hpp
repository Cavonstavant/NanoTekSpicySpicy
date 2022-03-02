/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"

namespace nts {
    class Component4069 : public AComponent {
        public:
            Component4069() = delete;
            explicit Component4069(const std::string &name) : AComponent(name){};
            Component4069(const Component4069 &other) = delete;
            Component4069 &operator=(const Component4069 &other) = delete;
            nts::Tristate compute(std::size_t pin) final;
            ~Component4069() override = default;

        protected:
        private:
    };
}// namespace nts

#endif /* !COMPONENT4069_HPP_ */
