#include "./ExpressionNode.hpp"
#include "ExpressionNode.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace nlohmann::literals;

namespace Ast{

    
    ExpressionNode::ExpressionNode() : Node(){}

    ExpressionNode::ExpressionNode(shared_ptr<Node> parent, ExpressionTypes expressionType) : Node(parent){
        _expressionType = expressionType;
    }

   
    string ExpressionNode::to_string()
    {
        string result = "Expression : ";
        result += "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
        result += "\n";
        return result;
    }

    string ExpressionNode::value()
    {
       return "Left : " + Left->value() + " Operator : " +  Op->value() + " Right Value: " + Right->value();
    }

    NodeType ExpressionNode::NType()
    {
        return NodeType::Expression;
    }

    shared_ptr<nlohmann::json> ExpressionNode::get_json()
    {
        json jsonObj;
        jsonObj["Left"] = *Left->get_json();
        jsonObj["Operator"] = Op->value();
        jsonObj["Right"] = *Right->get_json();
        return make_shared<json>(jsonObj);
    }

    

    ExpressionTypes ExpressionNode::ExpressionType()
    {
        return _expressionType;
    }

    void get_json(nlohmann::json& nlohmann_json_j, const ExpressionNode& node){

    }
}