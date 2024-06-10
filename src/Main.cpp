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
        ss << f.rdbuf(); // reading data
        str = ss.str();
    }
    cout<<str<<std::endl;

    std::stack<Token> tokens = tokenzie(str);

    while(tokens.size() > 0)
    {
        auto element = tokens.top();
        cout << element.type << ":" << element.value;
        cout << std::endl;
        tokens.pop();
    }
    cout << "finsihed";
    cout << std::endl;
    return 0;
}