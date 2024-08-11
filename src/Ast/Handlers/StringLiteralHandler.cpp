#include "StringLiteralHandler.hpp"
#include "../Nodes/TokenNode.hpp"

namespace Ast{

    Node* StringLiteralHandler::Handle(Node* parent, TokenProvider* tokenProvider, HandlerProvider* provider)
    {
        if(tokenProvider->hasNext() && tokenProvider->peek().type == TokenType::String)
        {
            auto token = tokenProvider->next();
            string cleansed;
            for(int i = 1; i < token.value.size()-1;i++)
            {
                cleansed += token.value[i];
            }
            token.value = cleansed;
            auto lit = new TokenNode(token, parent);
            return lit;
        }
        else return NULL;
    };
}