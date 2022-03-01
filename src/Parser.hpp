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
#include <map>
#include <list>
#include "Factory.hpp"

namespace nts {
class Parser {
public:
    Parser();
    ~Parser();
    // void fillCircuit(const std::string&, Circuit&);
    void fillMainBoard(const std::string&);
private:
    // std::list<std::reference_wrapper<IComponent>> _mainBoard;
    // std::list<IComponent &> _mainBoard;
    // std::list<std::reference_wrapper<std::unique_ptr<IComponent>>> _mainBoard;
    // std::map<std::string, std::reference_wrapper<std::unique_ptr<IComponent>>> _mainBoard;
    std::vector<std::unique_ptr<nts::IComponent>> _buffer;
    std::string trim(const std::string& str);
    std::string trimMiddle(std::string str);
    int findAny(std::string str, const char *chars);
    void createLink(std::string line, Factory &factory);
    void createChipset(std::string line, Factory &factory);
    // std::reference_wrapper<std::unique_ptr<nts::IComponent>> &findComponent(std::string name);
};
}

#endif /* !PARSER_HPP_ */
