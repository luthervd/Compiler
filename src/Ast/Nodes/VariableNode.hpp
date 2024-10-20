#pragma once
#include "../Lexer.hpp"
#include "Node.hpp"
#include "TokenNode.hpp"
#include "../Nodes/NumericLiteralNode.hpp"

namespace Ast{
    struct VariableNode : public Node{
        TokenNode type;
        TokenNode id;
        VariableNode(Token& type, Token& id);
        VariableNode(Token& type, Token& id, shared_ptr<Node> parent);
        string to_string();
        string value();
    };
}