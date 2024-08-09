#include "HandlerProvider.hpp"
#include "BinaryExpressionHandler.hpp"
#include "BinaryOperatorHandler.hpp"
#include "NumericLiteralHandler.hpp"

namespace Ast{
    HandlerProvider::HandlerProvider() {
        _handlers = map<HandlerType, Handler*>
        {
            {HandlerType::BinaryExpressionStatement, new BinaryExpressionHandler()},
            {HandlerType::BinaryOperator, new BinaryOperatorHandler()},
            {HandlerType::NumericLiteral, new NumericLiteralHandler()}
        };
    }
    
    Handler* HandlerProvider::GetHandler(HandlerType type){
        auto handler = _handlers.find(type);
        if(handler == _handlers.end()){
            return NULL;
        }
        else return handler->second;
    }
}
