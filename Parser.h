//
// Created by collin on 2/17/21.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <iostream>
#include <vector>
#include "Token.h"


class Parser {
private:
    int currentLocation = 0;
    const std::vector<Token>* tokens = nullptr;

    TokenType getNextType() const {
        return tokens->at(currentLocation).type;
    }

    /**
     * All these parse functions are the same idea. They parse the given thing.
     * They return false if there was a problem and true if success.
     */
    void adpop(TokenType type) {
        if (tokens->at(currentLocation).type == type) {
            currentLocation++;
        }
        else {
            throw &(tokens->at(currentLocation));
        }
    }

    void parseOperator() {
        if (getNextType() == TokenType::ADD)
            adpop(TokenType::ADD);
        else
            adpop(TokenType::MULTIPLY);
    }

    void parseParameter() {
        switch (getNextType()){
            case TokenType::STRING:
                adpop(TokenType::STRING);
                return;
            case TokenType::ID:
                adpop(TokenType::ID);
                return;
            default: parseExpression();
        }
    }

    void parseExpression() {
        adpop(TokenType::LEFT_PAREN);
        parseParameter();
        parseOperator();
        parseParameter();
        adpop(TokenType::RIGHT_PAREN);
    }

    void parseIDList() {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        adpop(TokenType::ID);
        parseIDList();
    }

    void parseStringList() {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        adpop(TokenType::STRING);
        parseStringList();
    }

    void parseParameterList() {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        parseParameter();
        parseParameterList();
    }

    void parsePredicate() {
        adpop(TokenType::ID);
        adpop(TokenType::LEFT_PAREN);
        parseParameter();
        parseParameterList();
        adpop(TokenType::RIGHT_PAREN);
    }

    void parsePredicateList() {
        if (getNextType() == TokenType::PERIOD) return;
        adpop(TokenType::COMMA);
        parsePredicate();
        parsePredicateList();
    }

    void parseHeadPredicate() {
        adpop(TokenType::ID);
        adpop(TokenType::LEFT_PAREN);
        adpop(TokenType::ID);
        parseIDList();
        adpop(TokenType::RIGHT_PAREN);
    }

    void parseQuery() {
        parsePredicate();
        adpop(TokenType::Q_MARK);
    }

    void parseRule() {
        parseHeadPredicate();
        adpop(TokenType::COLON_DASH);
        parsePredicate();
        parsePredicateList();
        adpop(TokenType::PERIOD);
    }

    void parseFact() {
        adpop(TokenType::ID);
        adpop(TokenType::LEFT_PAREN);
        adpop(TokenType::STRING);
        parseStringList();
        adpop(TokenType::RIGHT_PAREN);
        adpop(TokenType::PERIOD);
    }

    void parseScheme() {
        adpop(TokenType::ID);
        adpop(TokenType::LEFT_PAREN);
        adpop(TokenType::ID);
        parseIDList();
        adpop(TokenType::RIGHT_PAREN);
    }

    void parseQueryList() {
        if (getNextType() == TokenType::MY_EOF) return;
        parseQuery();
        parseQueryList();
    }

    void parseRuleList() {
        if (getNextType() == TokenType::QUERIES) return;
        parseRule();
        parseRuleList();
    }

    void parseFactList() {
        if (getNextType() == TokenType::RULES) return;
        parseFact();
        parseFactList();
    }

    void parseSchemeList() {
        if (getNextType() == TokenType::FACTS) return;
        parseScheme();
        parseSchemeList();
    }

    void parseDatalogProgram() {
        adpop(TokenType::SCHEMES);
        adpop(TokenType::COLON);
        parseScheme();
        parseSchemeList();
        adpop(TokenType::FACTS);
        adpop(TokenType::COLON);
        parseFactList();
        adpop(TokenType::RULES);
        adpop(TokenType::COLON);
        parseRuleList();
        adpop(TokenType::QUERIES);
        adpop(TokenType::COLON);
        parseQuery();
        parseQueryList();
        adpop(TokenType::MY_EOF);
    }

public:
    bool parse(const std::vector<Token>& tokens) {
        currentLocation = 0;
        this->tokens = &tokens;
        parseDatalogProgram();
        return true;
    }
};


#endif //UNTITLED_PARSER_H
