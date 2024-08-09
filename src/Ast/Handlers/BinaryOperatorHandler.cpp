#include "BinaryOperatorHandler.hpp"
#include "../Nodes/TokenNode.hpp"

namespace Ast{

    Node* BinaryOperatorHandler::Handle(Node* parent, TokenProvider* tokenProvider, HandlerProvider* handlerProvider)
    {
          if(tokenProvider->hasNext()){
            auto t = tokenProvider->next();
            return new TokenNode(t, parent);
        }
        else return NULL;
    }
}