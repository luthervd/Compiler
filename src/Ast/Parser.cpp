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
        auto binaryHandler = _handlerProvider->GetHandler(HandlerType::BinaryExpressionStatement);
        return binaryHandler->Handle(parent, _tokenProvider, _handlerProvider);
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