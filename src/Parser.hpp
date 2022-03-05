/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Circuit.hpp"
#include "Factory.hpp"
#include <memory>
#include <string>
#include <vector>

namespace nts {
class Parser {
public:
    Parser();
    ~Parser();
    void fillCircuit(const std::string &);
    Circuit getMainBoard() const;

private:
    std::vector<std::unique_ptr<nts::IComponent>> _buffer;
    std::string trim(const std::string &str);
    std::string trimMiddle(std::string str);
    int findAny(std::string str, const char *chars);
    void createLink(std::string line, Factory &factory);
    void createChipset(std::string line, Factory &factory);
    Circuit _mainBoard;
};
}// namespace nts

#endif /* !PARSER_HPP_ */
