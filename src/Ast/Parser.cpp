#include "Parser.hpp"


// E -> T { +|- } | T
namespace Ast {
    
    Parser::Parser(shared_ptr<TokenProvider> tokenProvider)
    { 
        _tokenProvider = tokenProvider;
        _handlerProvider = make_shared<HandlerProvider>();
    }

    shared_ptr<Node> Parser::Parse(){
        Token token = Token(TokenType::Program , "");
        auto program = make_shared<TokenNode>(token);
        while(_tokenProvider->hasNext())
        {
            parseStatement(program);
        }
        return program;
    }

    shared_ptr<Node> Parser::parseStatement(shared_ptr<Node> parent)
    {
        auto peeked = _tokenProvider->peek();
        shared_ptr<Handler> handler = nullptr;
        switch(peeked.type){
            case TokenType::EndStatement:
            {
              auto token = _tokenProvider->next();
              return make_shared<TokenNode>(token, parent);
            }
            case TokenType::BlockStatementStart:
              handler = _handlerProvider->GetHandler(HandlerType::BlockStatement);
              break;
            case TokenType::Type:
              handler = _handlerProvider->GetHandler(HandlerType::Variable);
              break;
            default:
              handler = _handlerProvider->GetHandler(HandlerType::ExpressionRoot);
              break;
        }
        if(handler == nullptr)
        {
            return nullptr;
        }
        return handler->Handle(parent, _tokenProvider, _handlerProvider);
    }

}