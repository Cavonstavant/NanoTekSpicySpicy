/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Simulation
*/

#include "Simulation.hpp"
#include <iostream>
#include <stdio.h>

nts::Simulation::Simulation(std::string const &fileName) {
    // _parser.fillCircuit(fileName);
    // _mainBoard = _parser.getMainBoard();
}

nts::Simulation::~Simulation() {
}

void nts::Simulation::execCommand(std::string const &command) {
    if (command.find("=") != std::string::npos) {
        try {
            std::string name = command.substr(0, command.find("="));
            std::string value = command.substr(command.find("=") + 1);
            // _mainBoard.editValue(name, value);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    } else if (command == "simulate") {
        // _mainBoard.simulate();
    } else if (command == "display") {
        // _mainBoard.display();
    } else if (command == "loop") {
        // _mainBoard.loop();
    } else if (command == "exit") {
        // _mainBoard.exit();
    } else if (command == "dump") {
        // _mainBoard.dump();
    } else {
        std::cerr << "Unknown command '" << command << "'." << std::endl;
    }
}

void nts::Simulation::runSimulation() {
    std::string line;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line))
            break;
        if (line == "exit")
            break;
        execCommand(line);
    }
}
