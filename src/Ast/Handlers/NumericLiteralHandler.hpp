#pragma once
#include "HandlerProvider.hpp"
#include "Handler.hpp"


namespace Ast{

    class NumericLiteralHandler : public Handler{
        Node* Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider);
    };
}