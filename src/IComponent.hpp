/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** IComponent
*/

#ifndef NANOTEKSPICE_ICOMPONENT_HPP
#define NANOTEKSPICE_ICOMPONENT_HPP

#include <string>

namespace nts
{
    enum class Tristate {
        UNDEFINED,
        TRUE,
        FALSE
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
            virtual void setPin(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
            virtual inline bool operator==(const IComponent &other) const = 0;
            virtual inline bool operator!=(const IComponent &other) const = 0;
            virtual void dump() const = 0;
            [[nodiscard]] virtual std::string getName() const = 0;
            virtual void setName(const std::string &name) = 0;
            [[nodiscard]] virtual Tristate pollState(size_t pin) const = 0;
            virtual void setState(size_t pin, Tristate new_state) = 0;
    };
}

#endif /* !NANOTEKSPICE_ICOMPONENT_HPP */
