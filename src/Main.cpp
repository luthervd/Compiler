#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Lexer.hpp"

using namespace std;
using namespace compilerLexer;

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
    cout<<str<<std::endl;

    std::vector<Token> tokens = tokenize(str);

    for(auto &token: tokens)
    {
        
        cout << print_token(token.type) << ":" << token.value;
        cout << std::endl;
    }
    cout << "finished";
    cout << std::endl;
    return 0;
}