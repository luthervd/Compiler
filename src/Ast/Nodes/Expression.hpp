#pragma once
#include "Node.hpp"

namespace Ast{

    struct Expression: public Node{
        shared_ptr<Node> Left;
        shared_ptr<Node> Right;
        shared_ptr<Node> Op;
        Expression();
        Expression(shared_ptr<Node> parent);
        string to_string();
        string value();
    };
}