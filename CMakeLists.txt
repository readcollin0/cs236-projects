cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(untitled main.cpp Automaton.h Token.h AutomataAll.h Tokenizer.cpp Tokenizer.h Token.cpp Parser.cpp Parser.h ProgramData.h)