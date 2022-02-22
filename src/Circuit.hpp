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
            void addComponent(nts::IComponent&);
            void removeComponent(nts::IComponent&);
            void simulate(std::size_t) override;
            void dump() const override;
            Tristate compute(std::size_t) override;
        protected:
        private:
            std::list<std::reference_wrapper<nts::IComponent>> _components;
            std::list<std::pair<std::size_t, Tristate>> _inputsBuffer;
    };
}

#endif /* !CIRCUIT_HPP_ */
