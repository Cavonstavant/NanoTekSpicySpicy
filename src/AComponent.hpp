/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Component
*/

#ifndef NANOTEKSPICE_ACOMPONENT_HPP
#define NANOTEKSPICE_ACOMPONENT_HPP

#include "IComponent.hpp"
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace nts
{
    struct LinkPair {
        LinkPair() = delete;
        LinkPair(size_t pin_self, size_t pin_other, IComponent& component) : component(component) {};
        ~LinkPair() = default;
        size_t pin_self{};
        size_t pin_other{};
        IComponent& component;
    };
    class AComponent : public IComponent {
        public:
            AComponent() = default;
            ~AComponent() override = default;
            explicit AComponent(const std::string& name);
            AComponent(const AComponent &other) = delete;
            AComponent &operator=(const AComponent &other) = delete;
            inline bool operator==(const AComponent &other) const { return this->_name == other._name; }
            inline bool operator!=(const AComponent &other) const { return !(*this == other); }
            void dump() const override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setName(const std::string &name) override;
            [[nodiscard]] std::string getName() const override;
            [[nodiscard]] Tristate pollState(size_t pin) const override;
            void setState(size_t pin, Tristate newState) override;
        protected:
            std::vector<std::reference_wrapper<LinkPair>> _links;
            std::vector<std::pair<std::size_t, Tristate>> _states;
            std::string _name;
        private:
    };
}

#endif /* !NANOTEKSPICE_ACOMPONENT_HPP */
