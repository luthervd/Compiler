#pragma once
#include "../Node.hpp"

namespace Ast{

    struct BinaryExpression: Node{
        Node* Left;
        Node* Right;
        Node* Op;
        BinaryExpression(Node* parent);
        string to_string();
        string value();
    };
}