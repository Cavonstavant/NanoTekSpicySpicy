/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** main
*/

#include "Exception.hpp"
#include <iostream>

int main(void) {
    try {
        throw nts::Exception::InvalidPinException("Invalid pin", 0);
    } catch (nts::Exception::InvalidPinException ex) {
        std::cout << "YeetException"
                  << " " << ex.what() << std::endl;
    }
    return 0;
}