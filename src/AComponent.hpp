/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace nts
{
    struct link_pair {
        size_t pin_self;
        size_t pin_other;
        IComponent* component;
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
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setName(const std::string &name) override;
            [[nodiscard]] std::string getName() const override;
            [[nodiscard]] Tristate pollState(size_t pin) const override;
            void setState(size_t pin, Tristate state) override;
        protected:
        private:
            std::string _name;
            std::vector<std::reference_wrapper<link_pair>> _links;
            std::vector<Tristate> _states;
    };
}

#endif /* !COMPONENT_HPP_ */
