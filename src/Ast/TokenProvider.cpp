#include "TokenProvider.hpp"

namespace Ast{

    TokenProvider::TokenProvider(const std::vector<Token>& tokens) : _tokens(tokens)
    {
        _index = 0;
    }
    
    TokenProvider::TokenProvider(const TokenProvider& tokenProvider) : _tokens(tokenProvider._tokens)
    {
        _index = tokenProvider._index;
    }
    
    const Token TokenProvider::next()
    {
        if(_index+1 < _tokens.size())
        {
            return _tokens[_index++];
        }
        else{
            return Token(TokenType::EOL,"No Token Found");
        }
    }
    
    const Token TokenProvider::peek()
    {
        
        if(!hasNext())
        {
            return Token(TokenType::None,"");
        }
        else{
            
            return _tokens[_index];
        }
    }

    const bool TokenProvider::hasNext()
    {
         return _index+1 < _tokens.size();
    }
}