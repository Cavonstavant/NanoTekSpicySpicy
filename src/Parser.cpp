/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
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
void nts::Parser::fillCircuit(const std::string& file, Circuit &circuit)
{
    std::ifstream input(file);
    std::string line;

    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    while (std::getline(input, line)) {
        if (line.empty() || line.starts_with('#'))
            continue;
        trimLine(line);
    }
}
