#include <stdexcept>
#include "Parser.hpp"


// E -> T { +|- } | T
namespace Ast {
    
    Parser::Parser(shared_ptr<TokenProvider> tokenProvider)
    { 
        _tokenProvider = tokenProvider;
        _handlerProvider = make_shared<HandlerProvider>();
    }

    shared_ptr<Node> Parser::Parse(){
        Token token = Token(TokenType::Program , "PROGRAM START");
        auto program = make_shared<TokenNode>(token);
        while(_tokenProvider->hasNext())
        {
            auto child = parseStatement(program);
            program->addChild(child);
        }
        return program;
    }

    shared_ptr<Node> Parser::parseStatement(shared_ptr<Node> parent)
    {
        auto peeked = _tokenProvider->peek();
        shared_ptr<Handler> handler = nullptr;
        switch(peeked.type){
            case TokenType::Type:
              handler = _handlerProvider->GetHandler(HandlerType::Variable);
              break;
        }
        if(handler == nullptr)
        {
            throw std::invalid_argument("No handler found for token " + peeked.to_string());
        }
        return handler->Handle(parent, _tokenProvider, _handlerProvider);
    }

}