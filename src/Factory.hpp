/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <string>
#include <memory>
#include <map>
#include <functional>
#include "IComponent.hpp"

namespace nts {
class Factory {
public:
    Factory();
    ~Factory();
    // std::function<std::unique_ptr<IComponent>(const std::string&)> getCreateFunction(const std::string&);
    std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

protected:
private:
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _factoryMap;
    [[nodiscard]] std::unique_ptr<nts::IComponent> createInput() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> createOutput() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create2716() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4001() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4008() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4011() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4013() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4017() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4030() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4040() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4069() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4071() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4081() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4094() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4514() const;
    [[nodiscard]] std::unique_ptr<nts::IComponent> create4801() const;
};
}// namespace nts

#endif /* !FACTORY_HPP_ */
