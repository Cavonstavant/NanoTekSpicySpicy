/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Simulation
*/

#include "Parser.hpp"
#include "Factory.hpp"

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

namespace nts {
class Simulation {
public:
    Simulation(std::string const &fileName);
    ~Simulation();
    void runSimulation();
    void execCommand(std::string const &command);

protected:
private:
    Parser _parser;
    // IComponent &_mainBoard;
};
}

#endif /* !SIMULATION_HPP_ */
