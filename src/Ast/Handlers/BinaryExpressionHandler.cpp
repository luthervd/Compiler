#include "BinaryExpressionHandler.hpp"

namespace Ast{
    shared_ptr<Node> BinaryExpressionHandler::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider,  shared_ptr<HandlerProvider> hProvider)
    {
        auto result = make_shared<ExpressionNode>(parent,ExpressionTypes::BinaryExpression);
        result->Left = this->HandleLeft(result, tProvider, hProvider);
        auto rightResponse = this->HandleRight(result, tProvider, hProvider);
        result->Op = rightResponse.OpResult;
        result->Right = rightResponse.RightNode;
        auto peeked = tProvider->peek();
        shared_ptr<ExpressionNode> finalResult;
        while(peeked.type == TokenType::BinaryPlus || peeked.type == TokenType::BinaryMinus || peeked.type == TokenType::BinaryMultiply || peeked.type == TokenType::BinaryDivision){
             finalResult = make_shared<ExpressionNode>(parent,ExpressionTypes::BinaryExpression);
             result->Parent = finalResult;
             finalResult->addChild(result);
             finalResult->Left = result;
             auto nextRightResponse = this->HandleRight(result, tProvider, hProvider);
             finalResult->Op = nextRightResponse.OpResult;
             finalResult->Right = nextRightResponse.RightNode;
             result = finalResult;
             peeked = tProvider->peek();
        }
        result->Parent = parent;
        parent->addChild(result);
        if(tProvider->peek().type == TokenType::EndStatement){
            auto eaten = tProvider->next();
        }
        return result;
    }

 
    shared_ptr<Node> BinaryExpressionHandler::HandleLeft(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        auto numberHandler = hProvider->GetHandler(HandlerType::NumericLiteral);
        auto peeked = tProvider->peek();
        if(peeked.type == TokenType::OpenParen)
        {
            auto binaryHandler = hProvider->GetHandler(HandlerType::BinaryExpressionStatement);
            auto eatenParam = tProvider->next();
            auto expression = binaryHandler->Handle(parent, tProvider, hProvider);
            auto eatenClose = tProvider->next();
            return expression;
        }
        else{
            return numberHandler->Handle(parent, tProvider, hProvider);
        }
    }

    RightResponse BinaryExpressionHandler::HandleRight(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        auto response = RightResponse();
                
        // SET OPERATOR
        auto opHandler = hProvider->GetHandler(HandlerType::BinaryOperator);
        auto op = opHandler->Handle(parent, tProvider, hProvider);
        response.OpResult = op;

       auto peeked = tProvider->peek();
       if(peeked.type == TokenType::OpenParen)
        {
            auto binaryHandler = hProvider->GetHandler(HandlerType::BinaryExpressionStatement);
            auto eatenParam = tProvider->next();
            auto expression = binaryHandler->Handle(parent, tProvider, hProvider);
            auto eatenClose = tProvider->next();
            response.RightNode = expression;
        }
        else{
            auto numberHandler = hProvider->GetHandler(HandlerType::NumericLiteral);
            response.RightNode = numberHandler->Handle(parent, tProvider, hProvider);
        }
        return response;
    }
}