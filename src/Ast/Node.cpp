#include "Node.hpp"

namespace Ast{
    
    Node::Node(){
        Parent = NULL;
        Children = vector<Node*>();
        
    }

    Node::Node(Node* node) {
        Parent = node;
        Parent->addChild(this);
        Children = vector<Node*>();
    }

    string Node::to_string()
    {
        return "base";
    }

    string Node::value()
    {
        return "Empty base node";
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

    void Node::addChild(Node* node){
        this->Children.push_back(node);
    }
}