#pragma once
#include "Node.hpp"

namespace Ast{

    struct AssignmentExpressionNode: public  Node{
        shared_ptr<Node> Left;
        shared_ptr<Node> Right;
        shared_ptr<Node> Op;
        AssignmentExpressionNode();
        AssignmentExpressionNode(shared_ptr<Node> parent);
        string to_string();
        string value();
    };
}