#include "./Expression.hpp"

namespace Ast{


    Expression::Expression() : Node(){}

    Expression::Expression(shared_ptr<Node> parent) : Node(parent){
    }
    

    string Expression::to_string()
    {
        string result = "Expression : ";
        result += "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
        result += "\n\r";
        return result;
    }

    string Expression::value()
    {
       return "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
    }

}