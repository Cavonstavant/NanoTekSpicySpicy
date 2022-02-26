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
#include <vector>
#include "Circuit.hpp"
#include "Factory.hpp"

namespace nts {
    class Parser {
        public:
            Parser();
            ~Parser();
            void fillCircuit(const std::string&, Circuit&);
        private:
            std::vector<std::unique_ptr<nts::IComponent>> _buffer;
            std::string trim(const std::string& str);
            std::string trimMiddle(std::string str);
            int findAny(std::string str, const char *chars);
            void createLink(std::string line, Circuit &mainBoard, Factory &factory);
            void createChipset(std::string line, Circuit &mainBoard, Factory &factory);
    };
}

#endif /* !PARSER_HPP_ */
