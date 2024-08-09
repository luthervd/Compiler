#pragma once
#include <vector>
#include "Lexer.hpp"

using namespace std;

namespace Ast{
    
    struct Node{
        vector<Node*> Children;
        Node* Parent;
        Node();
        Node(Node* parent);
        ~Node();
        void addChild(Node* child);
        virtual string to_string();
        virtual string value();
        string get_child_strings();
    };
}