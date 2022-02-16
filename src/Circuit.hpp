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
#include <memory>

namespace nts {
    class Circuit : public IComponent {
        public:
            Circuit() = default;
            ~Circuit() override = default;
            void addComponent(std::reference_wrapper<IComponent>);
            void removeComponent(std::reference_wrapper<nts::IComponent>);
            void simulate(std::size_t) override;
            Tristate compute(std::size_t) override;
        protected:
        private:
            std::list<std::reference_wrapper<nts::IComponent>> _components;

    };
}

#endif /* !CIRCUIT_HPP_ */
