cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(untitled main.cpp Automaton.h Token.h TokenType.h AutomatonComma.h AutomatonPeriod.h AutomatonQMark.h AutomataAll.h AutomatonLeftParen.h AutomatonRightParen.h AutomatonSingleChar.h AutomatonColon.h AutomatonMultiply.h AutomatonAdd.h AutomatonColonDash.h AutomatonSchemes.h AutomatonFacts.h AutomatonRules.h AutomatonQueries.h AutomatonID.h AutomatonString.h AutomatonComment.h AutomatonUndefined.h)