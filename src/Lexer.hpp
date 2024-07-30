#include <string>
#include <stack>
#include <vector>

namespace compilerLexer{

      enum TokenType {
            Number,
            Identifier,
            Equals,
            OpenParen,
            CloseParen,
            BinaryOperator,
            Type,
            Operator
    };

    struct Token {
       TokenType type;
       std::string value;
       Token(TokenType type, std::string value) : type(type), value(value)
       {
         
       }
    };

    std::vector<Token> tokenize(std::string &sourceCode);

    std::vector<std::string> splitString(const std::string &sourceCode);

    bool is_number(std::string value);

    std::string print_token(TokenType& type);
}