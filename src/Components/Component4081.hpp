/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"

namespace nts {
    class Component4081 : public AComponent {
        public:
            Component4081() = delete;
            explicit Component4081(const std::string &name) : AComponent(name){};
            Component4081(const Component4081 &other) = delete;
            Component4081 &operator=(const Component4081 &other) = delete;
            nts::Tristate compute(std::size_t pin) final;
            ~Component4081() override = default;

        protected:
        private:
    };
}// namespace nts

#endif /* !COMPONENT4081_HPP_ */
