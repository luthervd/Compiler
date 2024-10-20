#pragma once
#include "../Nodes/Node.hpp"
#include "../TokenProvider.hpp"
#include <map>
#include "HandlerType.hpp"

namespace Ast{

    class Handler;

    class HandlerProvider{
        public:
            HandlerProvider();
            shared_ptr<Handler> GetHandler(HandlerType type);
        private:
            std::map<HandlerType, shared_ptr<Handler>> _handlers;
    };  
}
