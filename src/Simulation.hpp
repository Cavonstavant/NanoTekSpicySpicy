/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Simulation
*/

#include "Factory.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"

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
        Circuit _mainBoard;
        // IComponent &_mainBoard;
    };
}// namespace nts

#endif /* !SIMULATION_HPP_ */
