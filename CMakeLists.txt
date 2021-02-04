cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(untitled main.cpp Automaton.h Token.h TokenType.h AutomataAll.h Tokenizer.cpp Tokenizer.h TokenType.cpp Token.cpp)