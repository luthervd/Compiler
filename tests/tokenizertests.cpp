#include <gtest/gtest.h>
#include "../src/Ast/Parser.hpp"

using namespace Ast;
using namespace std;

// Can read correct number of tokens for simple assignment;
TEST(TokenizerTests, BasicAssertions) {
  
  Tokenizer tokenizer = Tokenizer();
  string args = string("var x = 3;");
  auto result = tokenizer.tokenize(args);

  ASSERT_EQ(6,result.size());
}

//Contains the correct tokens for assigning number
TEST(TokenizerTests, CorrectAssignmentForNumber){
  Tokenizer tokenizer = Tokenizer();
  string args = string("var x = 3;");
  auto result = tokenizer.tokenize(args);

  ASSERT_EQ(TokenType::Type, result[0].type);
  ASSERT_EQ("var", result[0].value);

  ASSERT_EQ(TokenType::Identifier, result[1].type);
  ASSERT_EQ("x", result[1].value);

  ASSERT_EQ(TokenType::Equals, result[2].type);
  ASSERT_EQ("=", result[2].value);

  ASSERT_EQ(TokenType::Number, result[3].type);
  ASSERT_EQ("3", result[3].value);

  ASSERT_EQ(TokenType::EndStatement, result[4].type);
  ASSERT_EQ(";", result[4].value);
}


//Contains the correct tokens for assigning binary expression
TEST(TokenizerTests, CorrectAssignmentForBinaryPlus){
  Tokenizer tokenizer = Tokenizer();
  string args = string("var x = 3 + 4;");
  auto result = tokenizer.tokenize(args);

  ASSERT_EQ(TokenType::Type, result[0].type);
  ASSERT_EQ("var", result[0].value);

  ASSERT_EQ(TokenType::Identifier, result[1].type);
  ASSERT_EQ("x", result[1].value);

  ASSERT_EQ(TokenType::Equals, result[2].type);
  ASSERT_EQ("=", result[2].value);

  ASSERT_EQ(TokenType::Number, result[3].type);
  ASSERT_EQ("3", result[3].value);

  ASSERT_EQ(TokenType::BinaryPlus, result[4].type);
  ASSERT_EQ("+", result[4].value);

  ASSERT_EQ(TokenType::Number, result[5].type);
  ASSERT_EQ("4", result[5].value);

  ASSERT_EQ(TokenType::EndStatement, result[6].type);
  ASSERT_EQ(";", result[6].value);
}