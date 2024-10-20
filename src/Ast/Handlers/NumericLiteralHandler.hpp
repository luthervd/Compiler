#pragma once
#include "HandlerProvider.hpp"
#include "Handler.hpp"


namespace Ast{

    class NumericLiteralHandler : public Handler{
        shared_ptr<Node> Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider,  shared_ptr<HandlerProvider> provider);
    };
}