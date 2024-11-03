#pragma once
#include <vector>
#include <memory>
#include "../Lexer.hpp"
#include "NodeTypes.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

namespace Ast{
    
    struct Node : public std::enable_shared_from_this<Node>{
        vector<shared_ptr<Node>> Children;
        shared_ptr<Node> Parent;
        Node();
        Node(shared_ptr<Node> parent);
        ~Node();
        void addChild(shared_ptr<Node> child);
        virtual NodeType NType();
        virtual string to_string();
        virtual string value();
        virtual shared_ptr<nlohmann::json> get_json();
        string get_child_strings();
    };
}