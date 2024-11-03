#include "VariableNode.hpp"

namespace Ast{

    VariableNode::VariableNode(Token& type, Token& id): Node(), type(type), id(id){
    }

    VariableNode::VariableNode(Token& type, Token& id, shared_ptr<Node> parent): type(type), id(id), Node(parent){
    }

    string VariableNode::to_string(){
        string result = id.to_string() + "\n\r";
        result += get_child_strings();
        return result;
    }

    shared_ptr<nlohmann::json> VariableNode::get_json()
    {
        json jsonObj;
        jsonObj["value"] = id.value();
        return make_shared<json>(jsonObj);
    }

    string VariableNode::value()
    {
        return id.value();
    }
}