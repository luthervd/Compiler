#include "./BinaryExpression.hpp"

namespace Ast{


    BinaryExpression::BinaryExpression() : Node(){}

    BinaryExpression::BinaryExpression(Node* parent) : Node(parent){
    }
    

    string BinaryExpression::to_string()
    {
        string result = "Binary expression : ";
        result += "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
        result += "\n\r";
        return result;
    }

    string BinaryExpression::value()
    {
       return "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
    }

}