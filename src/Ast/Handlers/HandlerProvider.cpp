#include "HandlerProvider.hpp"
#include "BinaryExpressionHandler.hpp"
#include "BinaryOperatorHandler.hpp"
#include "NumericLiteralHandler.hpp"
#include "StringLiteralHandler.hpp"
#include "ExpressionBuilder.hpp"
#include "AssignmentExpressionHandler.hpp"

namespace Ast{
    HandlerProvider::HandlerProvider() {
        _handlers = map<HandlerType, shared_ptr<Handler>>
        {
            {HandlerType::BinaryExpressionStatement, make_shared<BinaryExpressionHandler>()},
            {HandlerType::BinaryOperator, make_shared<BinaryOperatorHandler>()},
            {HandlerType::NumericLiteral, make_shared<NumericLiteralHandler>()},
            {HandlerType::StringLiteral, make_shared<StringLiteralHandler>()},
            {HandlerType::ExpressionRoot, make_shared<ExpressionBuilder>()},
            {HandlerType::Variable, make_shared<AssignmentExpressionHandler>()}
        };
    }
    
    shared_ptr<Handler> HandlerProvider::GetHandler(HandlerType type){
        auto handler = _handlers.find(type);
        if(handler == _handlers.end()){
            return NULL;
        }
        else return handler->second;
    }
}
