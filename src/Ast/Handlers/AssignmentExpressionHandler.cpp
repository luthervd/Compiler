#include "AssignmentExpressionHandler.hpp"

namespace Ast{
    

    shared_ptr<Node> AssignmentExpressionHandler::Handle(shared_ptr<Node> parent, shared_ptr<TokenProvider> tokenProvider, shared_ptr<HandlerProvider> provider)
    {
        auto assignmentExpression = make_shared<ExpressionNode>(parent, ExpressionTypes::AssignmentExpression);
        assignmentExpression->Left = HandleLeft(parent,tokenProvider, provider);
        auto rightResult = HandleRight(parent,tokenProvider, provider);
        assignmentExpression->Op = rightResult.OpResult;
        assignmentExpression->Right = rightResult.RightNode;
        //Eat end 
        tokenProvider->next();
        return assignmentExpression;
    }

    shared_ptr<Node> AssignmentExpressionHandler::HandleLeft(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        if(tProvider->peek().type != TokenType::Type){
                throw std::invalid_argument("Should be assignment");
        }
        auto type = tProvider->next();
        auto id = tProvider->next();
        auto vNode = make_shared<VariableNode>(type, id, parent);
        return vNode;
         
    }

    RightResponse AssignmentExpressionHandler::HandleRight(shared_ptr<Node> parent, shared_ptr<TokenProvider> tProvider, shared_ptr<HandlerProvider> hProvider)
    {
        auto shouldBeEquals = tProvider->next();
        if(shouldBeEquals.type != TokenType::Equals && shouldBeEquals.value == "=")
        {
            throw std::invalid_argument("Should be Equals");
        }
        auto response = RightResponse();
        auto right = tProvider->next();
        response.OpResult = make_shared<TokenNode>(shouldBeEquals);
        response.RightNode = make_shared<NumericLiteralNode>(right, parent);
        return response;
    }

}
