#include "BinaryExpressionHandler.hpp"


namespace Ast{
    Node* BinaryExpressionHandler::Handle(Node* parent, TokenProvider* tokenProvider,  HandlerProvider* provider)
    {
        auto result = new BinaryExpression(parent);
        while(tokenProvider->hasNext())
        {
            Token token = tokenProvider->peek();
            //TODO make semicolon token type
            while(token.value != ";")
            {
                if(token.type == TokenType::Number)
                {
                  //TODO need better checking to make sure we dont read end of tokens
                  //Also is the right an id etc etc
                  auto numberHandler = provider->GetHandler(HandlerType::NumericLiteral);
                  auto opHandler = provider->GetHandler(HandlerType::BinaryOperator);
                  result->Left = numberHandler->Handle(result, tokenProvider, provider);
                  result->Op = opHandler->Handle(result, tokenProvider, provider);;
                  result->Right = numberHandler->Handle(result, tokenProvider, provider);
                  parent->addChild(result);
                }
                else
                {
                   return this->BuildOut(result, tokenProvider, provider);
                }
                token = tokenProvider->peek();
            }
            //Eat the semi-colon
            tokenProvider->next();

        }
        return result;
    }

    Node* BinaryExpressionHandler::BuildOut(BinaryExpression* parent, TokenProvider* tokenProvider,  HandlerProvider* provider)
    {
        auto result = new BinaryExpression(parent);
        if(tokenProvider->hasNext())
        {
            auto numberHandler = provider->GetHandler(HandlerType::NumericLiteral);
            auto opHandler = provider->GetHandler(HandlerType::BinaryOperator);
            Token token = tokenProvider->peek();
            //TODO make semicolon token type
            if(token.value != ";")
            {
                result->Left = parent;
                result->Op = opHandler->Handle(result, tokenProvider, provider);;
                result->Right = numberHandler->Handle(result, tokenProvider, provider);
                parent->addChild(result);
                return BuildOut(result, tokenProvider, provider);
            }
            else{
                  return result;
            }

        }
        return result;
      
    }
}