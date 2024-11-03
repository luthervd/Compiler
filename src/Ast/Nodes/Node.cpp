#include "Node.hpp"

namespace Ast{
    
    Node::Node(){
        Children = vector<shared_ptr<Node>>();
    }

    Node::Node(shared_ptr<Node> node){
        Parent = node;
        Children = vector<shared_ptr<Node>>();
    }

    string Node::to_string()
    {
        return "base";
    }

    string Node::value()
    {
        return "Empty base node";
    }

    shared_ptr<nlohmann::json> Node::get_json()
    {
        auto jsonChildren = json::array();
        for(auto child : Children)
        {
            auto childJson = child->get_json();
            jsonChildren.push_back(*childJson);
        }
        jsonChildren;
        return make_shared<json>(jsonChildren);
    }

    string Node::get_child_strings()
    {
        string result;
        for(auto child : Children)
        {
          result += child->to_string();
        }
        return result;
    }

    Node::~Node(){
        
    }

    NodeType Node::NType(){
        return NodeType::UNDEFINED;
    }

    void Node::addChild(shared_ptr<Node> node){
        Children.push_back(node);
    }
}