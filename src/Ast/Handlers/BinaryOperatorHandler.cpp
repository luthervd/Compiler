#include "BinaryOperatorHandler.hpp"
#include "../Nodes/TokenNode.hpp"

namespace Ast{

    shared_ptr<Node> BinaryOperatorHandler::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> handlerProvider)
    {
          if(tokenProvider->hasNext()){
            auto t = tokenProvider->next();
            auto node =  make_shared<TokenNode>(t, parent);
            return node;
        }
        else return NULL;
    }
}