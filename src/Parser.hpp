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
    };
}

#endif /* !PARSER_HPP_ */
