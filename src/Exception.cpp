/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#include "Exception.hpp"

nts::Exception::Exception(std::string const &message)
{
    _message = message;
}

const char *nts::Exception::what() const noexcept
{
    return _message.c_str();
}
