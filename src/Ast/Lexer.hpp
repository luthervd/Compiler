#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;

namespace Ast{

      enum TokenType {
            Program,
            Number,
            Identifier,
            Equals,
            OpenParen,
            CloseParen,
            BinaryPlus,
            BinaryPlusPlus,
            BinaryMinus,
            BinaryMinusMinus,
            BinaryMultiply,
            BinaryDivision,
            Type,
            Operator,
            EndStatement,
            EOL,
            None
    };

    struct Token {
       TokenType type;
       std::string value;
       Token(const Token& token);
       Token(TokenType type, std::string value);
       std::string to_string();
    };

    class Tokenizer{

        public:
        Tokenizer();
        std::vector<Token> tokenize(std::string &sourceCode);
        private:
        std::map<string, Token> _binaryMap;
    };

    std::vector<std::string> splitString(const std::string &sourceCode);

    bool is_number(std::string value);

    std::string print_token(TokenType& type);
}