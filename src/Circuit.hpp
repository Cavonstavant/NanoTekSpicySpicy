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
            void setLink(std::size_t, nts::IComponent &, std::size_t) override;
            void setPin(std::size_t, nts::IComponent &, std::size_t) override;
            inline bool operator==(const Circuit &other) const { return (this->_components == other._components);}
            inline bool operator!=(const Circuit &other) const { return !(*this == other);}
            [[nodiscard]] std::string getName() const override { return "";}
            void setName(const std::string &) override {}
            [[nodiscard]] nts::Tristate pollState(std::size_t) override;
            void setState(std::size_t, nts::Tristate) override;
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
