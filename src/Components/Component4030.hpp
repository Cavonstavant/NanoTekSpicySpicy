/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"
#include "../basic_gates/basic_gates.hpp"

namespace nts {
class Component4030 : public AComponent {
public:
    Component4030() = delete;
    ~Component4030() override = default;
    explicit Component4030(const std::string &name) : AComponent(name) {};
    Component4030(const Component4030 &other) = delete;
    Component4030 &operator=(const Component4030 &other) = delete;
    nts::Tristate compute(std::size_t pin) final;
protected:
private:
};
}// namespace nts

#endif /* !COMPONENT4030_HPP_ */
