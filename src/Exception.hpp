/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#define yeet(message) throw new nts::Exception(message)

#include <exception>
#include <string>

namespace nts {
    class Exception : std::exception {
        public:
            Exception(std::string const &message);
            const char *what() const noexcept;

        protected:
            std::string _message;

        private:
    };
}

#endif /* !EXCEPTION_HPP_ */
