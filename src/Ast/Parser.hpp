#pragma once
#include "Nodes/Node.hpp"
#include <vector>
#include <tuple>
#include <map>
#include "TokenProvider.hpp"
#include "Nodes/NumericLiteralNode.hpp"
#include "Nodes/ExpressionNode.hpp"
#include "Nodes/TokenNode.hpp"
#include "Handlers/Handler.hpp"
#include "Handlers/HandlerProvider.hpp"


using namespace std;

namespace Ast{

  class Parser{
    public:
      Parser(shared_ptr<TokenProvider> tokenProvider);
      shared_ptr<Node> Parse();
      
    private: 
      shared_ptr<TokenProvider> _tokenProvider;
      shared_ptr<HandlerProvider> _handlerProvider;
      shared_ptr<Node> parseStatement(shared_ptr<Node> parent);
      shared_ptr<Node> parseExpression(shared_ptr<Node> parent);
      shared_ptr<Node> parseExpressionStatement(shared_ptr<Node> parent);
  };

}