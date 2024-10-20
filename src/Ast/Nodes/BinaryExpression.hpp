#pragma once
#include "Expression.hpp"

namespace Ast{

    struct BinaryExpression: public Expression{
        BinaryExpression();
        BinaryExpression(shared_ptr<Node> parent);
        string to_string();
        string value();
    };
}