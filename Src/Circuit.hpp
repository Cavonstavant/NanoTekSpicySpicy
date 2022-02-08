/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <list>

namespace nts {
    class Circuit : public IComponent {
        public:
            Circuit();
            ~Circuit();
            void addComponent(IComponent&);
            void removeComponent(IComponent&);
            void simulate(std::size_t);
            Tristate compute(std::size_t);

        protected:
        private:
            std::list<IComponent> _components;

    };
}

#endif /* !CIRCUIT_HPP_ */
