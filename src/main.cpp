/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-constant.vigneron
** File description:
** main
*/

#include "Simulation.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./nanotekspice file.nts" << std::endl;
        return 84;
    }
    try {
        nts::Simulation simulation(av[1]);
        simulation.runSimulation();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
