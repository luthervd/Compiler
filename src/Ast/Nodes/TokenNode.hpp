#pragma once
#include "../Lexer.hpp"
#include "Node.hpp"

namespace Ast{
    struct TokenNode : public Node{
        Token token;
        TokenNode(Token& t);
        TokenNode(Token& token, shared_ptr<Node> parent);
        string to_string();
        string value();
        shared_ptr<nlohmann::json> get_json();
        NodeType NType();
    };
}