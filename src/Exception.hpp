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
    class NtsException : public std::exception {
        public:
            explicit NtsException(std::string const &message = "Not giving the context is bad");
            [[nodiscard]] const char *what() const noexcept override;

        protected:
            std::string _message;

        private:
    };
}

namespace nts::Exception {
    class YeetException : public NtsException
    {
        public:
            YeetException(std::string const &message = "yeet") : NtsException(message) {};
        // public:
        //     const char *what() const noexcept { return "yeet"; }
    };
    class ParserException : public NtsException {
        public:
            ParserException(std::string const &message) : NtsException(message) {};
    };
    class InvalidReadException : public ParserException {
        public:
            InvalidReadException(std::string const &message) : ParserException(message) {};
    };
    class InvalidSyntaxException : public InvalidReadException {
        public:
            InvalidSyntaxException(std::string const &message) : InvalidReadException(message) {};
    };
    class RuntimeException : public NtsException {
        public:
            RuntimeException(std::string const &message) : NtsException(message) {};
    };
    class ComputeException : public RuntimeException {
        public:
            ComputeException(std::string const &message) : RuntimeException(message) {};
    };
    class SimulateException : public RuntimeException {
        public:
            SimulateException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidPinException : public RuntimeException {
        public:
            InvalidPinException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidTypeException : public RuntimeException {
        public:
            InvalidTypeException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidValueException : public RuntimeException {
        public:
            InvalidValueException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidLinkException : public RuntimeException {
        public:
            InvalidLinkException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidComponentException : public RuntimeException {
        public:
            InvalidComponentException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidCircuitException : public RuntimeException {
        public:
            InvalidCircuitException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidFileException : public RuntimeException {
        public:
            InvalidFileException(std::string const &message) : RuntimeException(message) {};
    };
    class InvalidComponentNameException : public InvalidComponentException {
        public:
            InvalidComponentNameException(std::string const &message) : InvalidComponentException(message) {};
    };
    class RickException : public YeetException
    {
        public:
            RickException() : YeetException("Never gonna give you up, never gonna let you down, never gonna run around and desert you. Never gonna make you cry, never gonna say goodbye, never gonna tell a lie and hurt you.") {};
    };
    class AAAAAAAAAAAAAAAAAAAAAAAAException : public YeetException
    {
        public:
            AAAAAAAAAAAAAAAAAAAAAAAAException() : YeetException("AAAAAAAAAAAAAAAAAAAAAAAA") {};
    };
}

#endif /* !NANOTEKSPICE_EXCEPTION_HPP */
