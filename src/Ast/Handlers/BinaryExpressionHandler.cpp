#include "BinaryExpressionHandler.hpp"

// 2 + 2

// 2 + 2 - 2 

// 2 + 2 * 2
namespace Ast{
    Node* BinaryExpressionHandler::Handle(Node* parent, TokenProvider* tProvider,  HandlerProvider* hProvider)
    {
        auto result = new BinaryExpression();

        result->Left = this->HandleLeft(result, tProvider, hProvider);
        auto rightResponse = this->HandleRight(result, tProvider, hProvider);
        result->Op = rightResponse.OpResult;
        result->Right = rightResponse.RightNode;
        auto peeked = tProvider->peek();
        BinaryExpression* finalResult;
        while(peeked.type == TokenType::BinaryPlus || peeked.type == TokenType::BinaryMinus){
             finalResult = new BinaryExpression();
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
        tProvider->next();
        return result;
    }

 
    Node* BinaryExpressionHandler::HandleLeft(Node* parent, TokenProvider* tProvider, HandlerProvider* hProvider)
    {
        auto numberHandler = hProvider->GetHandler(HandlerType::NumericLiteral);
        auto peeked = tProvider->peek();
        if(peeked.type == TokenType::OpenParen)
        {
            //TODO this needs to handle any expression so just call Binary handle again
            auto eatenParam = tProvider->next();
            auto result = new BinaryExpression();
            auto opHandler = hProvider->GetHandler(HandlerType::BinaryOperator);
            auto left = numberHandler->Handle(result, tProvider, hProvider);
            auto op = opHandler->Handle(result, tProvider, hProvider);
            auto right = numberHandler->Handle(result, tProvider, hProvider);
            result->Left = left;
            result->Op = op;
            result->Right = right;

            // TODO Error handling
            auto eatenClose = tProvider->next();
            return result;

        }
        else{
            return numberHandler->Handle(parent, tProvider, hProvider);
        }
    }

    RightResponse BinaryExpressionHandler::HandleRight(Node* parent, TokenProvider* tProvider, HandlerProvider* hProvider)
    {
        auto response = RightResponse();
                
        // SET OPERATOR
        auto opHandler = hProvider->GetHandler(HandlerType::BinaryOperator);
        auto op = opHandler->Handle(parent, tProvider, hProvider);
        response.OpResult = op;

        //RIGHT - is it an expression?
        auto numberHandler = hProvider->GetHandler(HandlerType::NumericLiteral);
        auto rightNum = numberHandler->Handle(parent, tProvider, hProvider);
        auto peeked = tProvider->peek();
        
        //TODO include division also
        if(peeked.type == TokenType::BinaryMultiply)
        {
            auto mult = opHandler->Handle(parent, tProvider, hProvider);
            auto num = numberHandler->Handle(parent, tProvider, hProvider);
            auto binaryExpression = new BinaryExpression();
            binaryExpression->Left = rightNum;
            binaryExpression->Op = mult;
            binaryExpression->Right = num;
            response.RightNode = binaryExpression;
        }
        else{
           response.RightNode = rightNum;
        }
        return response;
    }
}