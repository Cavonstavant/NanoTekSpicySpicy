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
            void fillCircuit(std::string, Circuit&);
            std::unique_ptr<nts::IComponent> createComponent(const std::string& type);

        protected:
        private:
            std::unique_ptr<nts::IComponent> create1() const;

            std::unique_ptr<nts::IComponent> create4001() const;
            std::unique_ptr<nts::IComponent> create4013() const;
            std::unique_ptr<nts::IComponent> create4040() const;
    };
}

#endif /* !PARSER_HPP_ */
