/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** main
*/

#include "Exception.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"
#include <iostream>

int main()
{
    try {
        nts::Parser parser;
        nts::Circuit circuit;
        parser.fillCircuit()
    } catch (nts::Exception::YeetException& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}