#pragma once
#include "../Lexer.hpp"
#include "../Node.hpp"

namespace Ast{
    struct TokenNode : Node{
        Token token;
        TokenNode(Token& t);
        TokenNode(Token& token, Node* parent);
        string to_string();
        string value();
    };
}