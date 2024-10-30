#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include "./Lexer.hpp"

using namespace std;

namespace Ast{

    Token::Token(const Token& token){
        type = token.type;
        value = token.value;
    }
    
    Token::Token(TokenType type, std::string value){
        this->type = type;
        this->value = value;
    }

    std::string Token::to_string(){
        auto type = print_token(this->type);
        return type + " : " + this->value;
    }

    const unordered_set<char> ReservedOpChar = {
        '=', '+', '-', '/', '*', '<', '>', ';', '(',')','{','}'
    };

    const unordered_set<string> ReservedOpString = {
        "++", "+=", "-=", "<<", ">>"
    };

    const unordered_set<string> BooleanOps = {
        "&&", "||"
    };

    const unordered_set<char> Terminators = {
        ' ','\n','\r'
    };

    const unordered_set<string> AssignmentTypes = {
        "var"
    };

     std::vector<std::string> splitString(const std::string &sourceCode) {
        std::vector<std::string> words;
        std::string word;

        for (int i = 0; i < sourceCode.size(); i++) {
            
            char ch = sourceCode[i];
           
            //If not a terminator then handle
            if (Terminators.find(ch) == Terminators.end()) {

                 if(ReservedOpChar.find(ch) != ReservedOpChar.end()) {

                    //Clear the buffered word
                    if(word.length() > 0){
                        words.push_back(word);
                        word.clear();
                    }

                    //Check and push back the reserved string
                    string reservedOpStringTest = string() + ch + sourceCode[i+1];
                    if(ReservedOpString.find(reservedOpStringTest) != ReservedOpString.end())
                    {
                        // move iterator forward 
                        i += 1;

                        //push back the word
                        words.push_back(reservedOpStringTest);
                    }
                    else{
                        //Push back the reservered char
                        words.push_back(string() + ch);
                    }
                }
                else{
                    word += ch;
                }
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        return words;
    }

    bool is_number(string value){
        for(char& c : value){
            if(!isdigit(c)){
                return false;
            }
        }
        return true;
    }

    Tokenizer::Tokenizer(){
      this->_binaryMap = map<string, Token>
      {
        {"+",Token(TokenType::BinaryPlus, "+")},
        {"-",Token(TokenType::BinaryMinus, "-")},
        {"/",Token(TokenType::BinaryDivision, "/")},
        {"*",Token(TokenType::BinaryMultiply, "*")},
        {"++",Token(TokenType::BinaryPlusPlus, "++")},
        {"--",Token(TokenType::BinaryMinusMinus, "--")},
      };
    };

    std::vector<Token> Tokenizer::tokenize(std::string &sourceCode){
        std::vector<Token> tokens;
        std::vector<std::string> src = splitString(sourceCode);

        for(auto & value : src){
            if(value == "("){
                tokens.push_back(Token(TokenType::OpenParen, value));
            }
            else if(value == ")"){
                tokens.push_back(Token(TokenType::CloseParen, value));
            }
            else if(value[0] == '{'){
                tokens.push_back(Token(TokenType::BlockStatementStart, value));
            }
            else if(value[0] == '}'){
                tokens.push_back(Token(TokenType::BlockStatementEnd, value));
            }
            else if(value[0] == ';'){
                tokens.push_back(Token(TokenType::EndStatement, value));
            }
            else if(value[0] == '='){
                tokens.push_back(Token(TokenType::Equals, value));
            }
            else if(is_number(value)){
                tokens.push_back(Token(TokenType::Number, value));
            }
            else if(AssignmentTypes.find(value) != AssignmentTypes.end())
            {
                tokens.push_back(Token(TokenType::Type, value));
            }
            else if(value.size() == 1 && ReservedOpChar.find(value[0]) != ReservedOpChar.end())
            {
                auto binary = _binaryMap.find(value);
                if(binary != _binaryMap.end())
                {
                    Token token = binary->second;
                    tokens.push_back(token);
                }
                else{
                tokens.push_back(Token(TokenType::Operator, value));
                }
                
            }
            else if(ReservedOpString.find(value) != ReservedOpString.end())
            {
                tokens.push_back(Token(TokenType::Operator, value));
            }
            else if(value[0] == '"'){
                tokens.push_back(Token(TokenType::String, value));
            }
            else
            {
                tokens.push_back(Token(TokenType::Identifier, value));
            }
        }
        tokens.push_back(Token(TokenType::EOL,"END OF INPUT"));
        return tokens;
        
    }

    string print_token(TokenType& tokenType)
    {
        switch (tokenType)
        {
            case TokenType::BinaryPlus : 
            case TokenType::BinaryPlusPlus :
            case TokenType::BinaryDivision :
            case TokenType::BinaryMinus :
            case TokenType::BinaryMinusMinus :
            case TokenType::BinaryMultiply :
            return "BinaryOperator";
            case TokenType::CloseParen :
            case TokenType::OpenParen : return "Paren";
            case TokenType::Equals : return "Equals";
            case TokenType::Type : return "Reserved";
            case TokenType::Number : return "Number";
            case TokenType::Identifier : return "ID";
            case TokenType::Operator : return "Operator";
            case TokenType::Program : return "Program";
            case TokenType::EOL : return "End of File";
            case TokenType::String : return "String";
            default:
            return "UNDEFINED";
        };
    }
}