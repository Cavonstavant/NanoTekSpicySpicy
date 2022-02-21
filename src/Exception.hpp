/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#define yeet(message) throw new nts::NtsException::YeetException(message)

#include <exception>
#include <string>


namespace nts {
    class NtsException : std::exception {
        public:
            NtsException(std::string const &message);
            const char *what() const noexcept;

        protected:
            std::string _message;

        private:
    };
}

namespace nts {
    class YeetException : NtsException { const char *what() const noexcept { return "yeet"; }};
    class ParserException : NtsException {};
    class InvalidReadException : ParserException {};
    class InvalidSyntaxException : InvalidReadException {};
    class RuntimeException : NtsException {};
    class ComputeException : RuntimeException {};
    class SimulateException : RuntimeException {};
    class InvalidPinException : RuntimeException {};
    class InvalidTypeException : RuntimeException {};
    class InvalidValueException : RuntimeException {};
    class InvalidLinkException : RuntimeException {};
    class InvalidComponentException : RuntimeException {};
    class InvalidCircuitException : RuntimeException {};
    class InvalidFileException : RuntimeException {};
    class InvalidComponentNameException : InvalidComponentException {};
    class RickException : YeetException { const char *what() const noexcept { return "Never gonna give you up, never gonna let you down, never gonna run around and desert you. Never gonna make you cry, never gonna say goodbye. Never gonna tell a lie and hurt you."; }};
    class AAAAAAAAAAAAAAAAAAAAAAAAException : YeetException { const char *what() const noexcept { return "AAAAAAAAAAAAAAAAAAAAAAAA"; }};
}

#endif /* !EXCEPTION_HPP_ */
