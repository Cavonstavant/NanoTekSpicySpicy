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

namespace nts
{
    class Component : public IComponent {
        public:
            Component();
            ~Component();
            Tristate compute(std::size_t pi);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dump() const;
            void setPin(std::size_t pin, nts::IComponent &other);

        protected:
        private:
            std::map<std::size_t, IComponent&> _links;
            std::vector<nts::Tristate> _states;
    };
}

#endif /* !COMPONENT_HPP_ */
