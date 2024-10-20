#pragma once
#include "../Nodes/Node.hpp"
#include "../TokenProvider.hpp"
#include <map>
#include "HandlerType.hpp"

namespace Ast{

    class HandlerProvider;
    
    class Handler{
        public:
           virtual shared_ptr<Node> Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> provider) = 0;
    };

}