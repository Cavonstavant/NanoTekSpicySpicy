/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** IOComponent
*/

#ifndef IOCOMPONENT_HPP_
#define IOCOMPONENT_HPP_

#include "../AComponent.hpp"
#include "../Exception.hpp"

namespace nts {
    enum IOType {
        INPUT,
        OUTPUT
    };
    class IOComponent : public AComponent {
        public:
        IOComponent() = delete;
        IOComponent(IOType type) {
            _type = type;
        };
        IOComponent(const IOComponent &other) = default;
        IOComponent &operator=(const IOComponent &) = default;
        ~IOComponent() override = default;
        nts::Tristate compute(std::size_t pin) override {
            if (pin == 1)
                return std::get<Tristate>(_states[0]);
            throw nts::Exception::InvalidPinException("Invalid pin", 1);
        };
        void simulate(std::size_t pin) override {}
        [[nodiscard]] IOType getType() const {
            return _type;
        }
        void setType(IOType type) {
            _type = type;
        }

        protected:
        private:
        IOType _type;
        // std::reference_wrapper<LinkPair> _link;
        // std::vector<std::reference_wrapper<LinkPair>> _links;
    };

}// namespace nts

#endif /* !IOCOMPONENT_HPP_ */
