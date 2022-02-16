/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <memory>
#include "Circuit.hpp"

namespace nts {
    class Parser {
        public:
            Parser();
            ~Parser();
            void fillCircuit(const std::string&, Circuit&);
            std::unique_ptr<nts::IComponent> createComponent(const std::string& type);
        protected:
        private:
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4001(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4008(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4011(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4013(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4017(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4030(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4040(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4069(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4071(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4081(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4094(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4514(const std::string &name) const;
            [[nodiscard]]std::unique_ptr<nts::IComponent> create4801(const std::string &name) const;
    };
}

#endif /* !PARSER_HPP_ */
