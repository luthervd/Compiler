#pragma once
#include "Node.hpp"
#include <vector>
#include <tuple>
#include <map>
#include "TokenProvider.hpp"
#include "Nodes/NumericLiteralNode.hpp"
#include "Nodes/BinaryExpression.hpp"
#include "Nodes/TokenNode.hpp"
#include "Handlers/Handler.hpp"
#include "Handlers/HandlerProvider.hpp"


using namespace std;

namespace Ast{

  class Parser{
    public:
      Parser(TokenProvider* tokenProvider);
      ~Parser();
      Node* Parse();
      string to_string();
      
    private: 
      TokenProvider* _tokenProvider;
      HandlerProvider* _handlerProvider;
      Node* parseStatement(Node* parent);
      Node* parseExpression(Node* parent);
      Node* parseExpressionStatement(Node* parent);
  };

}