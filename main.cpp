#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "AutomataAll.h"
#define _DEBUG 0

using namespace std;

void setupAutomata();
void cleanUpAutomata();
void parseFile(string& file);

vector<Automaton*> automata;

int main(int argc, char* argv[]) {
#if _DEBUG == 0
    if (argc != 2) return 1;
    ifstream in(argv[1]);
    if (!in) return 2;
#endif

    setupAutomata();

#if _DEBUG // If in debug mode, just take input from console, for testing.
    string line, buf;
    while (true) {
        line = "";
        getline(cin, buf);
        while (buf.length() != 0) {
            line += buf + '\n';
            getline(cin, buf);
        }
        parseFile(line);
    }
#else
    ostringstream oss;
    oss << in.rdbuf();
    string file = oss.str();

    parseFile(file);
#endif

    cleanUpAutomata();
    return 0;
}

void findBestAutomaton(string& line, Automaton*& maxAuto, int& max) {
    for (Automaton *a : automata) {
        int result = a->Start(line);
        if (result > max) {
            max = result;
            maxAuto = a;
        }
    }
}

int skipSpace(string& line) {
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

void parseFile(string& file) {
    int lineNum = 1, tokens = 0;
    lineNum += skipSpace(file);
    Automaton *maxAuto = nullptr;

    while (file.length() > 0) {
        int max = 0;
        findBestAutomaton(file, maxAuto, max);

        if (max == 0) {
            cout << Token(TokenType::UNDEFINED, file.substr(0, 1), lineNum) << endl;
            file = file.substr(1);
        } else {
            cout << maxAuto->CreateToken(file.substr(0, max), lineNum) << endl;
            file = file.substr(max);
            lineNum += maxAuto->linesRead();
        }

        tokens++;
        lineNum += skipSpace(file);
    }

    //if (maxAuto == nullptr || maxAuto->getTokenType() != TokenType::UNDEFINED) {
        cout << Token(TokenType::MY_EOF, "", lineNum) << endl;
        tokens++;
    //}
    cout << "Total Tokens = " << tokens;
}

void setupAutomata() {
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

void cleanUpAutomata() {
    for (Automaton* aPtr : automata) {
        delete aPtr;
    }
}