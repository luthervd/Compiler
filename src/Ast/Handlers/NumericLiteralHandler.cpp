#include "NumericLiteralHandler.hpp"
#include "../Nodes/NumericLiteralNode.hpp"

namespace Ast{

    Node* NumericLiteralHandler::Handle(Node* parent, TokenProvider* tokenProvider, HandlerProvider* provider)
    {
        if(tokenProvider->hasNext() && tokenProvider->peek().type == TokenType::Number)
        {
            auto token = tokenProvider->next();
            auto lit = new NumericLiteralNode(token, parent);
            parent->addChild(lit);
            return lit;
        }
        else return NULL;
    };
}