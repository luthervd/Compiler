#pragma once
#include "Handler.hpp"
#include "HandlerProvider.hpp"

namespace Ast{

    class BinaryOperatorHandler : public Handler{
        shared_ptr<Node> Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> provider);
    };
}