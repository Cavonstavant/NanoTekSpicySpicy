/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
#include <fstream>

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

void nts::Parser::fillCircuit(const std::string& file, Circuit &circuit)
{
    std::ifstream input(file);
    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    std::string line;
    bool isLink = false;

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
