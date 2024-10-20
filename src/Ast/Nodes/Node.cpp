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

    void Node::addChild(shared_ptr<Node> node){
        Children.push_back(node);
    }
}