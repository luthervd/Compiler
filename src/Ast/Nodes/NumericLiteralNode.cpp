#include "./NumericLiteralNode.hpp"

namespace Ast{
    NumericLiteralNode::NumericLiteralNode(Token& token, shared_ptr<Node> parent): token(token), Node(parent){
    }

    string NumericLiteralNode::to_string()
    {
        return token.to_string();
    }

    string NumericLiteralNode::value()
    {
        return token.value;
    }
    
}
