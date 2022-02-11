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

namespace nts
{
    class Component : public IComponent {
        public:
            Component() = default;
            ~Component() override = default;
            explicit Component(const std::string& name);
            Component(const Component &other);
            Component &operator=(const Component &other);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setPin(std::size_t pin, nts::IComponent &other) override;
            void setName(const std::string &name);
            std::string getName() const;
        protected:
        private:
            std::string _name;
            std::map<std::size_t, IComponent&> _links;
            std::vector<Tristate> _states;
    };
}

#endif /* !COMPONENT_HPP_ */
