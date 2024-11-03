#pragma once
#include "./Handler.hpp"
#include "./HandlerProvider.hpp"
#include "../Nodes/ExpressionNode.hpp"


namespace Ast{

struct RightResponse {
        shared_ptr<Node> OpResult;
        shared_ptr<Node> RightNode;
};

class ExpressionHandler : public Handler{
        public:
           virtual shared_ptr<Node> Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider,  shared_ptr<HandlerProvider> provider) = 0;
        private:
           virtual shared_ptr<Node> HandleLeft(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider>  hProvider) = 0;
           virtual RightResponse HandleRight(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider) = 0;
};

}