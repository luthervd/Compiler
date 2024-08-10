#pragma once
#include "Handler.hpp"
#include "HandlerProvider.hpp"
#include "../Nodes/BinaryExpression.hpp"


namespace Ast{

    class BinaryExpressionHandler : public Handler{
        public:
           Node* Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider);
    };
}