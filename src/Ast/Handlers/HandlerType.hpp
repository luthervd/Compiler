#pragma once

namespace Ast{

    enum HandlerType{
        BlockStatement,
        ExpressionRoot,
        BinaryExpressionStatement,
        NumericLiteral,
        StringLiteral,
        BinaryOperator,
        Variable
    };
    
}