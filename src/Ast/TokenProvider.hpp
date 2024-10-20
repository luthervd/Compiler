#pragma once
#include "Lexer.hpp"
#include <vector>

namespace Ast {

    class TokenProvider {
        public:
            TokenProvider(const std::vector<Token>& tokens);
            TokenProvider(const TokenProvider& tokenProvider);
            const Token next();
            const Token peek();
            const bool hasNext();
        private:
            const std::vector<Token>& _tokens;
            int _index;
    };
}