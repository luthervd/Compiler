#pragma once
#include <vector>
#include <memory>
#include "../Lexer.hpp"

using namespace std;

namespace Ast{
    
    struct Node : public std::enable_shared_from_this<Node>{
        vector<shared_ptr<Node>> Children;
        shared_ptr<Node> Parent;
        Node();
        Node(shared_ptr<Node> parent);
        ~Node();
        void addChild(shared_ptr<Node> child);
        virtual string to_string();
        virtual string value();
        string get_child_strings();
    };
}