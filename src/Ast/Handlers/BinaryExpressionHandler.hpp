#pragma once
#include "ExpressionHandler.hpp"
#include "../Nodes/BinaryExpression.hpp"


namespace Ast{

    class BinaryExpressionHandler : public ExpressionHandler{
         public:
            shared_ptr<Node> Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider,  shared_ptr<HandlerProvider> provider);
        private:
            shared_ptr<Node> HandleLeft(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider);
            RightResponse HandleRight(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider);
    };

    
}