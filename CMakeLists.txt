cmake_minimum_required(VERSION 3.17)

project(Compiler)

add_executable(compiler
    src/Main.cpp
    src/Ast/Nodes/Node.cpp
    src/Ast/Parser.cpp
    src/Ast/Lexer.cpp
    src/Ast/TokenProvider.cpp
    src/Ast/Nodes/Expression.cpp
    src/Ast/Nodes/BinaryExpression.cpp
    src/Ast/Nodes/NumericLiteralNode.cpp
    src/Ast/Nodes/TokenNode.cpp
    src/Ast/Nodes/VariableNode.cpp
    src/Ast/Nodes/AssignmentExpressionNode.cpp
    src/Ast/Handlers/BinaryOperatorHandler.cpp
    src/Ast/Handlers/HandlerProvider.cpp
    src/Ast/handlers/NumericLiteralHandler.cpp
    src/Ast/Handlers/BinaryExpressionHandler.cpp
    src/Ast/Handlers/StringLiteralHandler.cpp
    src/Ast/Handlers/ExpressionBuilder.cpp
    src/Ast/Handlers/AssignmentExpressionHandler.cpp)