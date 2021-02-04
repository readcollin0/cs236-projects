//
// Created by collin on 1/29/21.
//

#ifndef UNTITLED_AUTOMATAALL_H
#define UNTITLED_AUTOMATAALL_H

#include "Automaton.h"

// Single character matching automaton.
class AutomatonSingleChar : public Automaton {
private:
    const char matchChar;
public:
    AutomatonSingleChar(char matchChar, TokenType type) : Automaton(type), matchChar(matchChar) {}
    virtual ~AutomatonSingleChar() {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, matchChar) == 1)
            return pos + 1;
        return 0;
    }

};


// Matches a comma
class AutomatonComma : public AutomatonSingleChar {
public:
    AutomatonComma() : AutomatonSingleChar(',', TokenType::COMMA) {}
};


// Matches a period
class AutomatonPeriod : public AutomatonSingleChar {
public:
    AutomatonPeriod() : AutomatonSingleChar('.', TokenType::PERIOD) {}
};


// Matches a question mark
class AutomatonQMark : public AutomatonSingleChar {
public:
    AutomatonQMark() : AutomatonSingleChar('?', TokenType::Q_MARK) {}
};


// Matches a left parenthesis
class AutomatonLeftParen : public AutomatonSingleChar {
public:
    AutomatonLeftParen() : AutomatonSingleChar('(', TokenType::LEFT_PAREN) {}
};


// Matches a right parenthesis
class AutomatonRightParen : public AutomatonSingleChar {
public:
    AutomatonRightParen() : AutomatonSingleChar(')', TokenType::RIGHT_PAREN) {}
};


// Matches a colon
class AutomatonColon : public AutomatonSingleChar {
public:
    AutomatonColon() : AutomatonSingleChar(':', TokenType::COLON) {}
};


// Matches ":-"
class AutomatonColonDash : public Automaton {
public:
    AutomatonColonDash() : Automaton(TokenType::COLON_DASH) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, ':') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, '-') == 1)
            return pos + 1;
        return 0;
    }
};


// Matches multiplication operator "*"
class AutomatonMultiply : public AutomatonSingleChar {
public:
    AutomatonMultiply() : AutomatonSingleChar('*', TokenType::MULTIPLY) {}
};


// Matches addition operator "+"
class AutomatonAdd : public AutomatonSingleChar {
public:
    AutomatonAdd() : AutomatonSingleChar('+', TokenType::ADD) {}
};


// Matches "Schemes"
class AutomatonSchemes : public Automaton {
public:
    AutomatonSchemes() : Automaton(TokenType::SCHEMES) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'S') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'c') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'h') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 'm') == 1)
            return s5(input, pos + 1);
        return 0;
    }

    int s5(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s6(input, pos + 1);
        return 0;
    }

    int s6(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};


// Matches "Facts"
class AutomatonFacts : public Automaton {
public:
    AutomatonFacts() : Automaton(TokenType::FACTS) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'F') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'a') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'c') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 't') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};


// Matches "Rules"
class AutomatonRules : public Automaton {
public:
    AutomatonRules() : Automaton(TokenType::RULES) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'R') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'u') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'l') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};


// Matches "Queries"
class AutomatonQueries : public Automaton {
public:
    AutomatonQueries() : Automaton(TokenType::QUERIES) {}

    int Start(const std::string& input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, 'Q') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, 'u') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s3(input, pos + 1);
        return 0;
    }

    int s3(const std::string& input, int pos) {
        if (checkChar(input, pos, 'r') == 1)
            return s4(input, pos + 1);
        return 0;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, 'i') == 1)
            return s5(input, pos + 1);
        return 0;
    }

    int s5(const std::string& input, int pos) {
        if (checkChar(input, pos, 'e') == 1)
            return s6(input, pos + 1);
        return 0;
    }

    int s6(const std::string& input, int pos) {
        if (checkChar(input, pos, 's') == 1)
            return pos + 1;
        return 0;
    }
};


// Matches an identifier, basically a variable name. A letter, followed by alphanumeric.
class AutomatonID : public Automaton {
public:
    AutomatonID() : Automaton(TokenType::ID) {}

    int Start(const std::string &input) {
        return s0(input, 0);
    }

private:
    int s0(const std::string& input, size_t pos) {
        if (input.length() <= pos) return 0;
        if (std::isalpha(input[pos]))
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, size_t pos) {
        if (input.length() > pos && isalnum(input[pos]))
            return s1(input, pos + 1);
        if (isReserved(input, pos))
            return 0;
        return pos;
    }

    bool isReserved(const std::string& input, int len) {
        if (len == 5) {
            return checkReserved(input, "Facts", len) || checkReserved(input, "Rules", len);
        } else if (len == 7) {
            return checkReserved(input, "Queries", len) || checkReserved(input, "Schemes", len);
        }
        return false;
    }

    bool checkReserved(const std::string& a, const std::string& reserved, int len) {
        return (a.substr(0, len) == reserved);
    }
};


// Matches a string. Starts with a "'", and matches anything. Escape a "'" with two of them "''".
class AutomatonString : public Automaton {
private:
    int linesReadCount;
public:
    AutomatonString() : Automaton(TokenType::STRING) {}

    int Start(const std::string& input) override {
        linesReadCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesReadCount;
    }

private:
    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        int state = checkChar(input, pos, '\'');
        switch (state) {
            case -1: return 0;
            case 1: return s2(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s1(input, pos + 1);
        }
        return -1; // SOMETHING BROKE, MAN.
    }

    int s2(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s1(input, pos + 1);
        return pos;
    }

    void checkNewLine(char c) {
        if (c == '\n') linesReadCount++;
    }
};


// Matches a comment. Either a single line, starting with #, or multi line #|<stuff>|#
class AutomatonComment : public Automaton {
private:
    int linesCount;
public:
    AutomatonComment() : Automaton(TokenType::COMMENT) {}

    int Start(const std::string& input) override {
        linesCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesCount;
    }

private:
    void checkNewLine(char c) {
        if (c == '\n') linesCount++;
    }

    int s0(const std::string& input, int pos) {
        if (checkChar(input, pos, '#') == 1)
            return s1(input, pos + 1);
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, '|') == 1)
            return s2(input, pos + 1);
        return s4(input, pos); // Do not digest any characters.
    }

    int s2(const std::string& input, int pos) {
        switch (checkChar(input, pos, '|')) {
            case 1: return s3(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return 0;
        }
        return -1;
    }

    int s3(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return pos + 1;
            case 0:
                checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return 0;
        }
        return -1;
    }

    int s4(const std::string& input, int pos) {
        if (checkChar(input, pos, '\n') == 0) // If it *did* find a character, but not \n
            return s4(input, pos + 1);
        return pos;
    }
};


// Matches an open comment or string.
class AutomatonUndefined : public Automaton {
private:
    int linesCount;
public:
    AutomatonUndefined() : Automaton(TokenType::UNDEFINED) {}


    int Start(const std::string& input) override {
        linesCount = 0;
        return s0(input, 0);
    }

    int linesRead() override {
        return linesCount;
    }

private:

    int s0(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return s1(input, pos + 1);
            case 0: if (input[pos] == '\'')
                    return s5(input, pos + 1);
                return 0;
            case -1: return 0;
        }
        return 0;
    }

    int s1(const std::string& input, int pos) {
        if (checkChar(input, pos, '|') == 1)
            return s2(input, pos + 1);
        return 0;
    }

    int s2(const std::string& input, int pos) {
        switch (checkChar(input, pos, '|')) {
            case 1: return s3(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return pos;
        }
        return -1;
    }

    int s3(const std::string& input, int pos) {
        switch (checkChar(input, pos, '#')) {
            case 1: return pos + 1;
            case 0: checkNewLine(input[pos]);
                return s2(input, pos + 1);
            case -1: return pos;
        }
        return -1;
    }

    int s5(const std::string& input, int pos) {
        int state = checkChar(input, pos, '\'');
        switch (state) {
            case -1: return pos;
            case 1: return s6(input, pos + 1);
            case 0:
                checkNewLine(input[pos]);
                return s5(input, pos + 1);
        }
        return -1; // SOMETHING BROKE, MAN.
    }

    int s6(const std::string& input, int pos) {
        if (checkChar(input, pos, '\'') == 1)
            return s5(input, pos + 1);
        return 0;
    }

    void checkNewLine(char c) {
        if (c == '\n') linesCount++;
    }
};

#endif //UNTITLED_AUTOMATAALL_H
