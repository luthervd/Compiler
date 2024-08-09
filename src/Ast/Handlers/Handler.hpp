#pragma once
#include "../Node.hpp"
#include "../TokenProvider.hpp"
#include <map>
#include "HandlerType.hpp"

namespace Ast{

    class HandlerProvider;
    
    class Handler{
        public:
           virtual Node* Handle(Node* parent, TokenProvider* tokenProvider, HandlerProvider* provider) = 0;
    };

}