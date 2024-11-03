#include "TokenNode.hpp"

namespace Ast{

    TokenNode::TokenNode(Token& t): Node(), token(t){
    }

    TokenNode::TokenNode(Token& t, shared_ptr<Node> parent): Node(parent), token(t){
    }

    string TokenNode::to_string(){
        string result = token.to_string() + "\n\r";
        result += get_child_strings();
        return result;
    }

    string TokenNode::value()
    {
        return token.value;
    }

    shared_ptr<nlohmann::json> TokenNode::get_json()
    {
        json jsonObj;
        jsonObj["value"] = token.value;
        auto children = Node::get_json();
        jsonObj["Children"] = *children;
        return make_shared<json>(jsonObj);
    }

    NodeType TokenNode::NType()
    {
        switch(token.type){
            case TokenType::Program:
               return NodeType::Programn;
            default:
               return NodeType::UNDEFINED;
        }
    }
}