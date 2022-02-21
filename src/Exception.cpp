/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#include "Exception.hpp"

nts::NtsException::NtsException(std::string const &message)
{
    _message = message;
}

const char *nts::NtsException::what() const noexcept
{
    return _message.c_str();
}
