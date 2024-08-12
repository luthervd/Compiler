#include "Parser.hpp"


// E -> T { +|- } | T
namespace Ast {
    
    Parser::Parser(TokenProvider* tokenProvider)
    { 
        _tokenProvider = tokenProvider;
        _handlerProvider = new HandlerProvider();
    }

    Parser::~Parser()
    {
     
    }

    Node* Parser::Parse(){
        Token token = Token(TokenType::Program , "");
        TokenNode* program = new TokenNode(token);
        while(_tokenProvider->hasNext())
        {
            parseExpressionStatement(program);
        }
        return program;
    }

    Node* Parser::parseExpressionStatement(Node* parent)
    {
        //TODO workout expression statement type
        auto peeked = _tokenProvider->peek();
        
        //TODO map token to handler type so we dont need switch
        Handler* handler = nullptr;
        switch(peeked.type){
            case TokenType::String:
              handler = _handlerProvider->GetHandler(HandlerType::StringLiteral);
              break;
            default:
              handler = _handlerProvider->GetHandler(HandlerType::BinaryExpressionStatement);
              break;
        }
        if(handler == nullptr)
        {
            return nullptr;
        }
        return handler->Handle(parent, _tokenProvider, _handlerProvider);
    }

    Node* Parser::parseStatement(Node* parent){
        //TODO more here 
        return parseExpression(parent);
    }

    Node* Parser::parseExpression(Node* parent)
    {
       //TODO workout expression type;
       return parseExpressionStatement(parent);
    }

}