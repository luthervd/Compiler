#pragma once

namespace Ast{

    enum NodeType{
        Programn,
        Expression,
        Declaration,
        Function,
        Literal,
        Class,
        UNDEFINED
    };

    enum ExpressionTypes{
        AssignmentExpression,
        BinaryExpression,
    };

    enum LiteralTypes{
        StringLit,
        NumberLit
    };
}