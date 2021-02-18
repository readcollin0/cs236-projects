//
// Created by collin on 2/17/21.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <set>
#include <vector>
#include "Token.h"
#include "ProgramData.h"


class Parser {
public:
    bool parse(const std::vector<Token>& tokens) {
        currentLocation = 0;
        this->tokens = &tokens;

        if (datalog) delete datalog;
        datalog = new Datalog();

        parseDatalogProgram();
        return true;
    }

    const Datalog& getDatalog() {
        return *datalog;
    }

private:
    int currentLocation = 0;
    const std::vector<Token>* tokens = nullptr;
    Datalog* datalog = nullptr;

    TokenType getNextType() const {
        return tokens->at(currentLocation).type;
    }

    /**
     * All these parse functions are the same idea. They parse the given thing.
     * They return false if there was a problem and true if success.
     */
    const Token& adpop(TokenType type) {
        if (tokens->at(currentLocation).type == type) {
            currentLocation++;
            const Token& token = tokens->at(currentLocation - 1);
            if (type == TokenType::STRING) {
                datalog->addToDomain(token.str);
            }
            return token;
        }
        else {
            throw &(tokens->at(currentLocation));
        }
    }

    std::string parseOperator() {
        if (getNextType() == TokenType::ADD) {
            adpop(TokenType::ADD);
            return "+";
        }
        else {
            adpop(TokenType::MULTIPLY);
            return "*";
        }
    }

    std::string parseParameter() {
        switch (getNextType()){
            case TokenType::STRING:
                return adpop(TokenType::STRING).str;
            case TokenType::ID:
                return adpop(TokenType::ID).str;
            default: return parseExpression();
        }
    }

    std::string parseExpression() {
        std::string expr;
        expr += adpop(TokenType::LEFT_PAREN).str;
        expr += parseParameter();
        expr += parseOperator();
        expr += parseParameter();
        expr += adpop(TokenType::RIGHT_PAREN).str;
        return expr;
    }

    void parseIDList(std::vector<std::string>& ids) {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        ids.push_back(adpop(TokenType::ID).str);
        parseIDList(ids);
    }

    void parseStringList(std::vector<std::string>& strings) {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        strings.push_back(adpop(TokenType::STRING).str);
        parseStringList(strings);
    }

    void parseParameterList(std::vector<std::string>& params) {
        if (getNextType() == TokenType::RIGHT_PAREN) return;
        adpop(TokenType::COMMA);
        params.push_back(parseParameter());
        parseParameterList(params);
    }

    Scheme parsePredicate() {
        Scheme predicate = Scheme(adpop(TokenType::ID).str);
        std::vector<std::string> params;

        adpop(TokenType::LEFT_PAREN);
        params.push_back(parseParameter());
        parseParameterList(params);
        adpop(TokenType::RIGHT_PAREN);

        predicate.addParameters(params);
        return predicate;
    }

    void parsePredicateList(std::vector<Scheme>& predicates) {
        if (getNextType() == TokenType::PERIOD) return;
        adpop(TokenType::COMMA);
        predicates.push_back(parsePredicate());
        parsePredicateList(predicates);
    }

    Scheme parseHeadPredicate() {
        Scheme predicate(adpop(TokenType::ID).str);
        std::vector<std::string> ids;

        adpop(TokenType::LEFT_PAREN);
        adpop(TokenType::ID);
        parseIDList(ids);
        adpop(TokenType::RIGHT_PAREN);

        predicate.addParameters(ids);
        return predicate;
    }

    void parseQuery() {
        datalog->addQuery(parsePredicate());
        adpop(TokenType::Q_MARK);
    }

    void parseRule() {
        Rule rule = Scheme(parseHeadPredicate());
        std::vector<Scheme> predicates;

        adpop(TokenType::COLON_DASH);
        predicates.push_back(parsePredicate());
        parsePredicateList(predicates);
        adpop(TokenType::PERIOD);

        rule.addPredicates(predicates);
        datalog->addRule(rule);
    }

    void parseFact() {
        Scheme fact = Scheme(adpop(TokenType::ID).str);
        std::vector<std::string> params;

        adpop(TokenType::LEFT_PAREN);
        params.push_back(adpop(TokenType::STRING).str);
        parseStringList(params);
        adpop(TokenType::RIGHT_PAREN);
        adpop(TokenType::PERIOD);

        fact.addParameters(params);
        datalog->addFact(fact);
    }

    void parseScheme() {
        Scheme scheme = Scheme(adpop(TokenType::ID).str);
        std::vector<std::string> parameters;

        adpop(TokenType::LEFT_PAREN);
        parameters.push_back(adpop(TokenType::ID).str);
        parseIDList(parameters);
        adpop(TokenType::RIGHT_PAREN);

        scheme.addParameters(parameters);
        datalog->addScheme(scheme);
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
};


#endif //UNTITLED_PARSER_H
