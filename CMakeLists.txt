cmake_minimum_required(VERSION 3.17)

project(Compiler)
include(FetchContent)

enable_testing()

#library 
add_library(ast)

target_sources(ast
PUBLIC
src/Ast/Serialize.cpp
src/Ast/Nodes/Node.cpp
src/Ast/Parser.cpp
src/Ast/Lexer.cpp
src/Ast/TokenProvider.cpp
src/Ast/Nodes/ExpressionNode.cpp
src/Ast/Nodes/NumericLiteralNode.cpp
src/Ast/Nodes/TokenNode.cpp
src/Ast/Nodes/VariableNode.cpp
src/Ast/Handlers/BinaryOperatorHandler.cpp
src/Ast/Handlers/HandlerProvider.cpp
src/Ast/handlers/NumericLiteralHandler.cpp
src/Ast/Handlers/BinaryExpressionHandler.cpp
src/Ast/Handlers/StringLiteralHandler.cpp
src/Ast/Handlers/ExpressionBuilder.cpp
src/Ast/Handlers/AssignmentExpressionHandler.cpp)


FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)

FetchContent_MakeAvailable(json)

target_link_libraries(ast PUBLIC nlohmann_json::nlohmann_json)
#main
add_executable(compiler src/Main.cpp)
target_link_libraries(compiler PUBLIC ast)

#test

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  compiler_tests
  tests/tokenizertests.cpp
  tests/parsertests.cpp
)
target_link_libraries(
  compiler_tests
  GTest::gtest_main
  ast
)
target_include_directories(
  compiler_tests
  PRIVATE
  src/Ast
  src/Ast/Handlers
  src/Ast/Nodes
)

include(GoogleTest)
gtest_discover_tests(compiler_tests)