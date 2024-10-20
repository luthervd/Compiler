#include "./AssignmentExpressionNode.hpp"

namespace Ast{


    AssignmentExpressionNode::AssignmentExpressionNode() : Node(){}

    AssignmentExpressionNode::AssignmentExpressionNode(shared_ptr<Node> parent) : Node(parent){
    }
    

    string AssignmentExpressionNode::to_string()
    {
        string result = "Assignment expression : ";
        result += "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
        result += "\n\r";
        return result;
    }

    string AssignmentExpressionNode::value()
    {
       return "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
    }

}