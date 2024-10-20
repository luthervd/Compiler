#include "NumericLiteralHandler.hpp"
#include "../Nodes/NumericLiteralNode.hpp"

namespace Ast{

    shared_ptr<Node> NumericLiteralHandler::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> provider)
    {
        if(tokenProvider->hasNext() && tokenProvider->peek().type == TokenType::Number)
        {
            auto token = tokenProvider->next();
            auto lit = make_shared<NumericLiteralNode>(token, parent);
            parent->addChild(lit);
            return lit;
        }
        else return NULL;
    };
}