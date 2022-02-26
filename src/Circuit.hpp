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
            virtual void setLink(std::size_t, nts::IComponent &, std::size_t) override = 0;

            void simulate(std::size_t) override;
            void dump() const override;
            Tristate compute(std::size_t) override;
        protected:
        private:
            std::list<std::reference_wrapper<nts::IComponent>> _inputs;
            std::list<std::reference_wrapper<nts::IComponent>> _outputs;
            std::list<std::pair<std::size_t, Tristate>> _inputsBuffer;
            std::list<std::pair<std::size_t, Tristate>> _outputsBuffer;
    };
}

#endif /* !CIRCUIT_HPP_ */
