#pragma once
#include "Handler.hpp"
#include "HandlerProvider.hpp"

namespace Ast{

    class BinaryOperatorHandler : public Handler{
        Node* Handle(Node* parent, TokenProvider* tokenProvider, HandlerProvider* provider);
    };
}