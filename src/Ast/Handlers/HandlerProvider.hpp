#pragma once
#include "../Node.hpp"
#include "../TokenProvider.hpp"
#include <map>
#include "HandlerType.hpp"

namespace Ast{

    class Handler;

    class HandlerProvider{
        public:
            HandlerProvider();
            Handler* GetHandler(HandlerType type);
        private:
            std::map<HandlerType, Handler*> _handlers;
    };  
}
