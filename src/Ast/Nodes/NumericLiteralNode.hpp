#pragma once
#include "../Node.hpp"

namespace Ast{

    struct NumericLiteralNode : Node{
        Token token;
        NumericLiteralNode(Token& token, Node* parent);
        string to_string();
        string value();
    };
}