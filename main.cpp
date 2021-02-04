#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

#include "Tokenizer.h"
#define _DEBUG 0

using namespace std;

vector<Automaton*> automata;

void printTokens(vector<Token>& tokens);

int main(int argc, char* argv[]) {
#if _DEBUG == 0
    if (argc != 2) return 1;
    ifstream in(argv[1]);
    if (!in) return 2;
#endif

    Tokenizer tokenizer;

#if _DEBUG // If in debug mode, just take input from console, for testing.
    string file, buf;
    while (true) {
        file = "";
        getline(cin, buf);
        while (buf.length() != 0) {
            file += buf + '\n';
            getline(cin, buf);
        }
        vector<Token> tokens = tokenizer.parseFile(file);
        printTokens(tokens);
        cout << endl << endl;
    }
#else
    ostringstream oss;
    oss << in.rdbuf();
    string file = oss.str();

    vector<Token> tokens = tokenizer.parseFile(file);
    printTokens(tokens);
#endif

    return 0;
}

void printTokens(vector<Token>& tokens) {
    for (size_t i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
    }
    cout << "Total Tokens = " << tokens.size();
}