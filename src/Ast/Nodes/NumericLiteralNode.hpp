#pragma once
#include "Node.hpp"

namespace Ast{

    struct NumericLiteralNode : public Node{
        Token token;
        NumericLiteralNode(Token& token, shared_ptr<Node> parent);
        string to_string();
        string value();
    };
}