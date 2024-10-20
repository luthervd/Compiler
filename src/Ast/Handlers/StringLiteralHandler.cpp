#include "StringLiteralHandler.hpp"
#include "../Nodes/TokenNode.hpp"

namespace Ast{

    shared_ptr<Node> StringLiteralHandler::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        if(tProvider->hasNext() && tProvider->peek().type == TokenType::String)
        {
            auto token = tProvider->next();
            string cleansed;
            for(int i = 1; i < token.value.size()-1;i++)
            {
                cleansed += token.value[i];
            }
            token.value = cleansed;
            auto lit = make_shared<TokenNode>(token, parent);
            auto delim = tProvider->next();
            return lit;
        }
        else return NULL;
    };
}