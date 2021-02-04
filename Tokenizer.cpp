//
// Created by collin on 2/3/21.
//

#include "Tokenizer.h"

void Tokenizer::setupAutomata() {
    automata.push_back(new AutomatonComma());
    automata.push_back(new AutomatonPeriod());
    automata.push_back(new AutomatonQMark());
    automata.push_back(new AutomatonLeftParen());
    automata.push_back(new AutomatonRightParen());
    automata.push_back(new AutomatonColon());
    automata.push_back(new AutomatonColonDash());
    automata.push_back(new AutomatonMultiply());
    automata.push_back(new AutomatonAdd());
    automata.push_back(new AutomatonSchemes());
    automata.push_back(new AutomatonFacts());
    automata.push_back(new AutomatonRules());
    automata.push_back(new AutomatonQueries());
    automata.push_back(new AutomatonID());
    automata.push_back(new AutomatonString());
    automata.push_back(new AutomatonComment());
    automata.push_back(new AutomatonUndefined());
}

void Tokenizer::cleanUpAutomata() {
    for (Automaton* aPtr : automata) {
        delete aPtr;
    }
}

// HELPER FUNCTION
void findBestAutomaton(const std::vector<Automaton*>& automata, std::string& line, Automaton*& maxAuto, int& max) {
    for (Automaton *a : automata) {
        int result = a->Start(line);
        if (result > max) {
            max = result;
            maxAuto = a;
        }
    }
}

// HELPER FUNCTION
int skipSpace(std::string& line) {
    int skips = 0, lines = 0;
    while (isspace(line[skips])) {
        if (line[skips] == '\n')
            lines++;
        skips++;
    }

    if (skips > 0)
        line = line.substr(skips);

    return lines;
}

std::vector<Token> Tokenizer::parseFile(std::string file) {
    std::vector<Token> tokens;
    int lineNum = 1;
    Automaton *maxAuto = nullptr;

    lineNum += skipSpace(file);
    while (file.length() > 0) {
        int max = 0;
        findBestAutomaton(automata, file, maxAuto, max);

        if (max == 0) {
            tokens.push_back(Token(TokenType::UNDEFINED, file.substr(0, 1), lineNum));
            file = file.substr(1);
        } else {
            tokens.push_back(maxAuto->CreateToken(file.substr(0, max), lineNum));
            file = file.substr(max);
            lineNum += maxAuto->linesRead();
        }

        lineNum += skipSpace(file);
    }

    tokens.push_back(Token(TokenType::MY_EOF, "", lineNum));
    return tokens;
}