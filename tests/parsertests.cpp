#include <gtest/gtest.h>
#include "../src/Ast/Parser.hpp"

using namespace Ast;
using namespace std;

// Demonstrate some basic assertions.
TEST(ParserTests, BasicAssertions) {
  // Expect two strings not to be equal.
  Tokenizer tokenizer = Tokenizer();
  string args = string("");
  auto result = tokenizer.tokenize(args);
  auto tokenProvider = make_shared<TokenProvider>(result);
  auto parser = Parser(tokenProvider);
  auto parsed = parser.Parse();
}