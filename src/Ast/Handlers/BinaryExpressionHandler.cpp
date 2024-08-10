#include "BinaryExpressionHandler.hpp"


namespace Ast{
    Node* BinaryExpressionHandler::Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider)
    {
        auto result = new BinaryExpression();
        auto numberHandler = provider->GetHandler(HandlerType::NumericLiteral);
        auto opHandler = provider->GetHandler(HandlerType::BinaryOperator);
        auto left = numberHandler ->Handle(result, tokenProvider, provider);
        auto op = opHandler->Handle(result, tokenProvider, provider);
        auto right = numberHandler->Handle(result, tokenProvider, provider);
        result->Left = left;
        result->Op = op;
        result->Right = right;
        auto peeked = tokenProvider->peek();
        BinaryExpression* finalResult;
        while(peeked.type == TokenType::BinaryPlus || peeked.type == TokenType::BinaryMinus){
             finalResult = new BinaryExpression();
             auto nextOp = opHandler->Handle(finalResult, tokenProvider, provider);
             auto nextRight = numberHandler->Handle(finalResult, tokenProvider, provider);
             result->Parent = finalResult;
             finalResult->addChild(result);
             finalResult->Left = result;
             finalResult->Right = nextRight;
             finalResult->Op = nextOp;
             result = finalResult;
             peeked = tokenProvider->peek();
        }
        result->Parent = parent;
        parent->addChild(result);
        tokenProvider->next();
        return result;
    }
}