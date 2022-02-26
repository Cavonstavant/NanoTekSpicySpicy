/*
** EPITECH PROJECT, 2022
** NanoTekSpicySpicy
** File description:
** IOComponent
*/

#ifndef IOCOMPONENT_HPP_
#define IOCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts {
    typedef enum IOType {
        INPUT,
        OUTPUT
    };
    class IOComponent : public AComponent {
        public:
            IOComponent();
            ~IOComponent();
            IOType getType() const { return _type; }
            void setType(IOType type) { _type = type; }

        protected:
        private:
            IOType _type;
            // std::reference_wrapper<LinkPair> _link;
            // std::vector<std::reference_wrapper<LinkPair>> _links;
    };
}

#endif /* !IOCOMPONENT_HPP_ */
