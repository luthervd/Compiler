#pragma once
#include "Node.hpp"
#include "NodeTypes.hpp"

namespace Ast{
    
    struct ExpressionNode: public Node{
        public:
            shared_ptr<Node> Left;
            shared_ptr<Node> Right;
            shared_ptr<Node> Op;
            ExpressionNode();
            ExpressionNode(shared_ptr<Node> parent, ExpressionTypes expressionType);
            string to_string();
            string value();
            NodeType NType();
            shared_ptr<nlohmann::json> get_json();
            ExpressionTypes ExpressionType();
        private:
            ExpressionTypes _expressionType;

    };
}