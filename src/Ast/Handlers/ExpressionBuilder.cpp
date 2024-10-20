#include "./ExpressionBuilder.hpp"

namespace Ast{
    shared_ptr<Node> ExpressionBuilder::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> handlerProvider)
    {
        auto token = tokenProvider->peek();
        //TODO work out expression type
        auto binaryOperatorHandler = handlerProvider->GetHandler(HandlerType::BinaryExpressionStatement);
        return binaryOperatorHandler->Handle(parent, tokenProvider, handlerProvider);
    }

    shared_ptr<Node> ExpressionBuilder::HandleLeft(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        return nullptr;
    }

    RightResponse ExpressionBuilder::HandleRight(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        return RightResponse();
    }
}