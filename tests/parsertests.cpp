#include <gtest/gtest.h>
#include "../src/Ast/Parser.hpp"

using namespace Ast;
using namespace std;

// Demonstrate some basic assertions.
TEST(ParserTests, CanAddAssignmentExpression) {
  // Expect two strings not to be equal.
  Tokenizer tokenizer = Tokenizer();
  string args = string("var x = 3");
  auto result = tokenizer.tokenize(args);
  auto tokenProvider = make_shared<TokenProvider>(result);
  auto parser = Parser(tokenProvider);
  auto parsed = parser.Parse();

  auto dump = parsed->to_string();
  ASSERT_EQ(1, parsed->Children.size()) << dump;
}

TEST(ParserTests, AssignmentExpressionIsCorrect) {
  // Expect two strings not to be equal.
  Tokenizer tokenizer = Tokenizer();
  string args = string("var x = 3");
  auto result = tokenizer.tokenize(args);
  auto tokenProvider = make_shared<TokenProvider>(result);
  auto parser = Parser(tokenProvider);
  auto parsed = parser.Parse();

  auto dump = parsed->to_string();
  auto child = parsed->Children[0];
  auto expressionNode = dynamic_pointer_cast<ExpressionNode>(child);
  ASSERT_EQ(0, parsed->Children[0]->Children.size()) << dump;
  ASSERT_EQ(ExpressionTypes::AssignmentExpression, expressionNode->ExpressionType());

}

TEST(ParserTests, CanAssignInt) {
  // Expect two strings not to be equal.
  Tokenizer tokenizer = Tokenizer();
  string args = string("int x = 3");
  auto result = tokenizer.tokenize(args);
  auto tokenProvider = make_shared<TokenProvider>(result);
  auto parser = Parser(tokenProvider);
  auto parsed = parser.Parse();

  auto dump = parsed->to_string();
  auto child = parsed->Children[0];
  auto expressionNode = dynamic_pointer_cast<ExpressionNode>(child);
  ASSERT_EQ(0, parsed->Children[0]->Children.size()) << dump;
  ASSERT_EQ(ExpressionTypes::AssignmentExpression, expressionNode->ExpressionType());

}


TEST(ParserTests, JsonOutPutIsCorrect) {
  // Expect two strings not to be equal.
  Tokenizer tokenizer = Tokenizer();
  string args = string("int x = 3");
  auto result = tokenizer.tokenize(args);
  auto tokenProvider = make_shared<TokenProvider>(result);
  auto parser = Parser(tokenProvider);
  auto parsed = parser.Parse();
  auto jsonResult = parsed->get_json();

  ASSERT_EQ("{\"Children\":[{\"Left\":{\"value\":\"x\"},\"Operator\":\"=\",\"Right\":{\"value\":\"3\"}}],\"value\":\"PROGRAM START\"}",jsonResult->dump());
}
