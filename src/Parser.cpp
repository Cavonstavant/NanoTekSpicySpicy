/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
#include "Circuit.hpp"
#include "Components/IOComponent.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

// nts::Circuit &nts::Parser::getMainBoard() const
// {
//     return _mainBoard;
// }

// nts::Circuit nts::Parser::getMainBoard() const {
//     return _mainBoard;
// }

static inline void trimLine(std::string &line)
{
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char c) {
                   return !std::isspace(c);
               }));
    line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char c) {
                   return !std::isspace(c) || c == '#';
               }).base(),
               line.end());
}

static size_t strtosize(const std::string &str)
{
    size_t size = 0;
    std::stringstream ss;
    ss << str;
    ss >> size;
    return size;
}

// std::reference_wrapper<std::unique_ptr<nts::IComponent>> &nts::Parser::findComponent(std::string name)
// {
//     for (std::reference_wrapper<std::unique_ptr<IComponent>> &component: _mainBoard) {
//         if (component.get().get()->getName() == name) {
//             return component;
//         }
//     }
//     return nullptr;
// }

/**
 * @brief parse the file given with the path and fills the circuit
 * @param file
 * @param circuit
 * @throw nts::ParserError
 * @throw nts::Exception::RuntimeException if the file can't be open
 */
void nts::Parser::createLink(std::string line, Factory &factory, Circuit &circuit)
{
    std::string component1;
    std::string component2;
    std::string pin1;
    std::string pin2;
    std::string newLine = line;

    try {
        // std::cout << line << std::endl;
        component1 = newLine.substr(0, newLine.find(":"));
        // std::cout << component1 << std::endl;
        newLine = newLine.substr(newLine.find(":") + 1);
        pin1 = newLine.substr(0, newLine.find(" "));
        // std::cout << pin1 << std::endl;
        newLine = newLine.substr(newLine.find(" ") + 1);
        component2 = newLine.substr(0, newLine.find(":"));
        // std::cout << component2 << std::endl;
        newLine = newLine.substr(newLine.find(":") + 1);
        pin2 = newLine;
        // std::cout << pin2 << std::endl;
        // std::cout << std::endl;
    } catch (std::exception &e) {
        throw nts::Exception::InvalidSyntaxException("Invalid syntax");
    }
    if (component1 == component2 && pin1 == pin2)
        throw nts::Exception::VeryStupidUserError("You can't link a component's pin to itself");

    try {
        // circuit.setLink(component1, pin1, component2, pin2);
        // _mainBoard[component1].get().setLink(strtosize(pin1), _mainBoard[component2].get(), strtosize(pin2));
    } catch (std::exception &e) {
        throw nts::Exception::InvalidSyntaxException("Invalid syntax");
    }


    // mainBoard[component1]->setLink(pin1, mainBoard[component2], pin2);
    // _mainBoard[component1]->setLink(pin1, _mainBoard[component2], pin2);

    // std::reference_wrapper<std::unique_ptr<nts::IComponent>> &component1Ref = findComponent(component1);
    // for (std::reference_wrapper<std::unique_ptr<IComponent>> &component: _mainBoard) {
    //     if (component.get().get()->getName() == component1) {
    //         component.get().get()->setLink(strtosize(pin1), component1Ref.get().get(), strtosize(pin2));
    //         return;
    //     }
    // }
}

void nts::Parser::createChipset(std::string line, Factory &factory, Circuit &circuit)
{
    std::string type;
    std::string name;

    try {
        // std::cout << line << std::endl;
        type = line.substr(0, line.find(" "));
        // std::cout << type << std::endl;
        name = line.substr(line.find(" ") + 1);
        // std::cout << name << std::endl;
        // std::cout << std::endl;
    } catch (std::exception) {
        throw nts::Exception::InvalidReadException("Invalid syntax");
    }
    try {
        if (type == "input")
            circuit.addInputComponent(name, factory.createComponent(type));
        else if (type == "output")
            circuit.addOutputComponent(name, factory.createComponent(type));
        else
            circuit.addComponent(name, factory.createComponent(type));
        // _mainBoard.
        // _mainBoard.emplace(std::make_pair(name, factory.createComponent(type)));
        // mainBoard.addComponent(factory.createComponent(type));
    } catch (std::exception) {
        throw nts::Exception::InvalidComponentNameException("Invalid component name");
    }
}

void nts::Parser::fillCircuit(const std::string &file, Circuit &circuit)
{
    std::ifstream input(file);
    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    std::string line;
    bool isLink = false;
    Factory factory;

    while (std::getline(input, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#')
            continue;
        if (line.rfind(".links:", 0) == 0) {
            isLink = true;
            continue;
        } else if (line.rfind(".chipsets:", 0) == 0) {
            isLink = false;
            continue;
        } else if (isLink == false) {
            createChipset(line, factory, circuit);
        } else {
            createLink(line, factory, circuit);
        }
    }
}

int nts::Parser::findAny(std::string str, const char *chars)
{
    for (int i = 0; i < str.length(); i++)
        for (int c = 0; chars[c]; c++)
            if (str[i] == chars[c])
                for (int j = 0; j < i; j++)
                    if (str[i + 1] == chars[j])
                        return i;
    return -1;
}

std::string nts::Parser::trimMiddle(std::string str)
{
    size_t pos = 0;

    while (pos != -1) {
        pos = findAny(str, " \n\v\f\r\t\0");
        if (pos != -1) {
            str.erase(pos, 1);
        }
    }
    return str;
}

std::string nts::Parser::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        first = 0;
    size_t last = str.find_last_not_of(' ');
    if (last == std::string::npos)
        last = str.length();
    return trimMiddle(str.substr(first, (last - first + 1)));
    // return trimMiddle(str.substr(first, (last - first + 1)));
}
