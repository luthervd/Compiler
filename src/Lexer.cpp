#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include "./Lexer.hpp"

using namespace std;

namespace compilerLexer{

    const unordered_set<char> Reserved = {
        ';', '(',')','=','+','/','*'
    };

    const unordered_set<char> Terminators = {
        ' ','\n','\r'
    };

     std::vector<std::string> splitString(const std::string &sourceCode) {
        std::vector<std::string> words;
        std::string word;

        for (char ch : sourceCode) {
            if (Terminators.find(ch) == Terminators.end()) {
                if(Reserved.find(ch) != Reserved.end()) {
                    if(word.length() > 0){
                        words.push_back(word);
                        word.clear();
                    }
                    words.push_back(string() + ch);
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

    std::stack<Token> tokenzie(std::string &sourceCode){
        std::stack<Token> tokens;
        std::vector<std::string> src = splitString(sourceCode);

        for(auto & value : src){
            if(value == "("){
                tokens.push(Token(TokenType::OpenParen, value));
            }
            else if(value == ")"){
                tokens.push(Token(TokenType::CloseParen, value));
            }
            else if(is_number(value)){
                tokens.push(Token(TokenType::Number, value));
            }
            else if(value == "int" || value == "string" || value == "bool" || value == "decimal" || value == "if")
            {
                tokens.push(Token(TokenType::Identifier, value));
            }
        }
        return tokens;
    }



   

}