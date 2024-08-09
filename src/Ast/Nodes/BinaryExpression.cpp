#include "./BinaryExpression.hpp"

namespace Ast{


    BinaryExpression::BinaryExpression(Node* parent) : Node(parent){
    }
    

    string BinaryExpression::to_string()
    {
        string result = "Binary expression : ";
        result += Left->value() + " " + Op->value() + " " + Right->value();
        result += "\n\r";
        return result;
    }

    string BinaryExpression::value()
    {
       return Left->value() + " " + Op->value() + " " + Right->value();
    }

}