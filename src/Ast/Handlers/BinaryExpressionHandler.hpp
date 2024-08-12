#pragma once
#include "Handler.hpp"
#include "HandlerProvider.hpp"
#include "../Nodes/BinaryExpression.hpp"


namespace Ast{

     struct RightResponse {
             Node* OpResult;
             Node* RightNode;
     };

    class BinaryExpressionHandler : public Handler{
        public:
           Node* Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider);
        private:
           Node* HandleLeft(Node* parent, TokenProvider* tProvider, HandlerProvider* hProvider);
           RightResponse HandleRight(Node* parent, TokenProvider* tProvider, HandlerProvider* hProvider);
    };

    
}