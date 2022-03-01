/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#ifndef NANOTEKSPICE_EXCEPTION_HPP
#define NANOTEKSPICE_EXCEPTION_HPP

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
}// namespace nts

namespace nts::Exception {
class ParserException : public NtsException {
public:
    explicit ParserException(std::string const &message) : NtsException(message) {};
};
class InvalidReadException : public ParserException {
public:
    explicit InvalidReadException(std::string const &message) : ParserException(message) {};
};
class InvalidSyntaxException : public InvalidReadException {
public:
    explicit InvalidSyntaxException(std::string const &message) : InvalidReadException(message) {};
};
class RuntimeException : public NtsException {
public:
    explicit RuntimeException(std::string const &message) : NtsException(message) {};
};
class ComputeException : public RuntimeException {
public:
    explicit ComputeException(std::string const &message) : RuntimeException(message) {};
};
class SimulateException : public RuntimeException {
public:
    explicit SimulateException(std::string const &message) : RuntimeException(message) {};
};
class InvalidPinException : public RuntimeException {
public:
    InvalidPinException() = delete;
    explicit InvalidPinException(std::string const &message, size_t pin) : RuntimeException(message) {};
    /**
    * @brief get the invalid pin number
    * @return pin number
    */
    [[nodiscard]] size_t getPin() const noexcept {
        return _pin;
    }

private:
    size_t _pin{};
};
class UnknownPinException : public RuntimeException {
public:
    UnknownPinException() = delete;
    explicit UnknownPinException(std::string const &message, size_t pin) : RuntimeException(message) {};
    /**
    * @brief Get the missing Pin number
    * @return pin number
    */
    [[nodiscard]] size_t getPin() const noexcept {
        return _pin;
    }

private:
    size_t _pin{};
};
class InvalidTypeException : public RuntimeException {
public:
    explicit InvalidTypeException(std::string const &message) : RuntimeException(message) {};
};
class InvalidValueException : public RuntimeException {
public:
    explicit InvalidValueException(std::string const &message) : RuntimeException(message) {};
};
class InvalidLinkException : public RuntimeException {
public:
    explicit InvalidLinkException(std::string const &message) : RuntimeException(message) {};
};
class InvalidComponentException : public RuntimeException {
public:
    explicit InvalidComponentException(std::string const &message) : RuntimeException(message) {};
};
class InvalidCircuitException : public RuntimeException {
public:
    explicit InvalidCircuitException(std::string const &message) : RuntimeException(message) {};
};
class InvalidFileException : public RuntimeException {
public:
    explicit InvalidFileException(std::string const &message) : RuntimeException(message) {};
};
class InvalidComponentNameException : public InvalidComponentException {
public:
    explicit InvalidComponentNameException(std::string const &message) : InvalidComponentException(message) {};
};
class VeryStupidUserError : public InvalidSyntaxException {
public:
    VeryStupidUserError(std::string const &message = "please stop") : InvalidSyntaxException(message) {};
};
}// namespace nts::Exception

#endif /* !NANOTEKSPICE_EXCEPTION_HPP */
