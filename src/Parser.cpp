/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
#include "IOComponent.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <fstream>
#include <sstream>

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

static inline void trimLine(std::string& line)
{
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char c) { return !std::isspace(c); }));
    line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char c) { return !std::isspace(c) || c == '#'; }).base(), line.end());
}

/**
 * @brief parse the file given with the path and fills the circuit
 * @param file
 * @param circuit
 * @throw nts::ParserError
 */
void nts::Parser::createLink(std::string line, Circuit &mainBoard, Factory &factory)
{}

void nts::Parser::createChipset(std::string line, Circuit &mainBoard, Factory &factory)
{
    std::string type;
    std::string name;

    try {
        type = line.substr(0, line.find(" "));
        name = line.substr(line.find(" ") + 1);
    } catch (std::exception) {
        throw nts::Exception::InvalidReadException("Invalid syntax");
    }

    if (line.rfind("input", 0)) {
        IOComponent component(name);
        component.setType(nts::IOType::INPUT);
        mainBoard.addComponent(component);
    }

    else if (line.rfind("output", 0)) {
        IOComponent component(name);
        component.setType(nts::IOType::OUTPUT);
        mainBoard.addComponent(component);
    }

    // else {
    //     try {
    //         mainBoard.addComponent(std::reference_wrapper<IComponent>(factory.createComponent(type)));
    //     } catch (std::exception) {
    //         throw nts::Exception::InvalidComponentNameException("Invalid component name");
    //     }
    // }
}

void nts::Parser::fillCircuit(const std::string& file, Circuit &circuit)
{
    std::ifstream input(file);
    std::string line;

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
            createChipset(line, circuit, factory);
        } else {
            createLink(line, circuit, factory);
        }
    }
}

int nts::Parser::findAny(std::string str, const char *chars)
{
    for (int i = 0; i < str.length(); i++)
        for (int c = 0; chars[c]; c++)
            if (str[i] == chars[c])
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

std::string nts::Parser::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return trimMiddle(str.substr(first, (last - first + 1)));
}
