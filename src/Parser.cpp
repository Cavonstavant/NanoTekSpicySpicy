/*
** EPITECH PROJECT, 2022
** bootstrap_nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "AComponent.hpp"
#include "Exception.hpp"
#include <fstream>
#include <sstream>

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

static void preParseFile(const std::string& file)
{
    std::ofstream tmp("tmp_" + file);
    std::ifstream input(file);
    std::string line;


    if (!input.is_open())
        throw nts::Exception::RuntimeException("Can't open file");
    while (std::getline(input, line)) {
        if (line.empty() || line.starts_with('#'))
            continue;
        line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char c) { return !std::isspace(c); }));
        line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char c) { return !std::isspace(c) || c == '#'; }).base(), line.end());
        tmp << line << std::endl;
    }
}

/**
 * @brief parse the file given with the path and fills the circuit
 * @param file
 * @param circuit
 * @throw nts::ParserError
 * @throw nts::Exception::RuntimeException if the file can't be open
 */
void nts::Parser::fillCircuit(const std::string& file, Circuit &circuit)
{
    preParseFile(file);
}
