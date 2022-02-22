/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#ifndef NANOTEKSPICE_EXCEPTION_HPP
#define NANOTEKSPICE_EXCEPTION_HPP

#define yeet throw nts::Exception::YeetException()

#include <exception>
#include <string>


namespace nts {
    class NtsException : std::exception {
        public:
            explicit NtsException(std::string const &message = "Not giving the context is bad");
            [[nodiscard]] const char *what() const noexcept override;

        protected:
            std::string _message;

        private:
    };
}

namespace nts::Exception {
    class YeetException : NtsException
    {
        public:
            [[nodiscard]] const char *what() const noexcept override { return "yeet"; }
    };
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
    class RickException : YeetException
    {
        public:
            [[nodiscard]] const char *what() const noexcept override { return "Never gonna give you up, never gonna let you down, never gonna run around and desert you. Never gonna make you cry, never gonna say goodbye, never gonna tell a lie and hurt you."; }
    };
    class AAAAAAAAAAAAAAAAAAAAAAAAException : YeetException
    {
        public:
            [[nodiscard]] const char *what() const noexcept override { return "AAAAAAAAAAAAAAAAAAAAAAAA"; }
    };
}

#endif /* !NANOTEKSPICE_EXCEPTION_HPP */
