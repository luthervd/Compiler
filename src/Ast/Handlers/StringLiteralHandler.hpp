#pragma once
#include "HandlerProvider.hpp"
#include "Handler.hpp"


namespace Ast{

    class StringLiteralHandler : public Handler{
        Node* Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider);
    };
}