#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include "Ast/Parser.hpp"
#include "Ast/Lexer.hpp"
#include "Ast/TokenProvider.hpp"

using namespace std;
using namespace Ast;

int main()
{
    ifstream f("../test.xp"); //taking file as inputstream
    string str;
    if(f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading datcda
        str = ss.str();
    }
    else{
        cout << "No file found";
    }    
    Tokenizer tokenizer = Tokenizer();
    std::vector<Token> tokens = tokenizer.tokenize(str);
    auto tokenProvider = make_shared<TokenProvider>(tokens);
    auto parser = make_shared<Parser>(tokenProvider);
    
    auto result = parser->Parse();

    cout << *result->get_json();
    cout << "finished";
    cout << std::endl;
    return 0;
}