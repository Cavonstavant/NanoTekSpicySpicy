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
    explicit IOComponent(IOType type);
    IOComponent(const IOComponent &other) = default;
    IOComponent &operator=(const IOComponent &) = default;
    ~IOComponent() override = default;
    nts::Tristate compute(std::size_t pin) override;
    void simulate(std::size_t pin) override {}
    [[nodiscard]] IOType getType() const;
    void setType(IOType type);

protected:
private:
    IOType _type;
    // std::reference_wrapper<LinkPair> _link;
    // std::vector<std::reference_wrapper<LinkPair>> _links;
};

}// namespace nts

#endif /* !IOCOMPONENT_HPP_ */
