//
// Created by collin on 2/17/21.
//

#ifndef UNTITLED_PROGRAMDATA_H
#define UNTITLED_PROGRAMDATA_H

#include <string>
#include <ostream>
#include <vector>
#include <set>

class Scheme {
private:
    std::string name;
    std::vector<std::string> parameters;
public:
    Scheme(std::string name) : name(name) {}

    void addParameter(const std::string& param) {
        parameters.push_back(param);
    }

    void addParameters(const std::vector<std::string>& params) {
        for (std::string param : params)
            parameters.push_back(param);
    }

    const std::string& getName() const {
        return name;
    }

    const std::vector<std::string>& getParameters() const {
        return parameters;
    }

    friend std::ostream& operator<<(std::ostream& out, const Scheme& scheme) {
        out << scheme.name << "(";

        size_t i = 0;
        while (i < scheme.parameters.size() - 1)
            out << scheme.parameters[i++] << ",";
        out << scheme.parameters[i] << ")";

        return out;
    }
};


class Rule {
private:
    Scheme head;
    std::vector<Scheme> predicates;
public:
    Rule(Scheme head) : head(head) {}

    void addPredicate(Scheme predicate) {
        predicates.push_back(predicate);
    }

    void addPredicates(std::vector<Scheme> predicates) {
        for (Scheme predicate : predicates)
            this->predicates.push_back(predicate);
    }

    const Scheme& getHead() const {
        return head;
    }

    const std::vector<Scheme>& getPredicates() const {
        return predicates;
    }

    friend std::ostream& operator<<(std::ostream& out, const Rule& rule) {
        out << rule.head << " :- ";

        size_t i = 0;
        while (i < rule.predicates.size() - 1)
            out << rule.predicates[i++] << ",";
        out << rule.predicates[i] << "";

        return out;
    }
};

class Datalog {
private:
    std::vector<Scheme> schemes;
    std::vector<Scheme> facts;
    std::vector<Rule> rules;
    std::vector<Scheme> queries;
    std::set<std::string> domain;

public:
    void addScheme(Scheme scheme) {
        schemes.push_back(scheme);
    }

    void addFact(Scheme fact) {
        facts.push_back(fact);
    }

    void addRule(Rule rule) {
        rules.push_back(rule);
    }

    void addQuery(Scheme query) {
        queries.push_back(query);
    }

    void addToDomain(std::string str) {
        domain.insert(str);
    }

    const std::vector<Scheme>& getSchemes() const {
        return schemes;
    }

    const std::vector<Scheme>& getFacts() const {
        return facts;
    }

    const std::vector<Rule>& getRules() const {
        return rules;
    }

    const std::vector<Scheme>& getQueries() const {
        return queries;
    }

    const std::set<std::string>& getDomain() const {
        return domain;
    }

    friend std::ostream& operator<<(std::ostream& out, const Datalog& datalog) {
        out << "Schemes(" << datalog.schemes.size() << "):" << std::endl;
        for (Scheme scheme : datalog.schemes)
            out << "  " << scheme << std::endl;

        out << "Facts(" << datalog.facts.size() << "):" << std::endl;
        for (Scheme fact : datalog.facts)
            out << "  " << fact << "." << std::endl;

        out << "Rules(" << datalog.rules.size() << "):" << std::endl;
        for (Rule rule : datalog.rules)
            out << "  " << rule << "." << std::endl;

        out << "Queries(" << datalog.queries.size() << "):" << std::endl;
        for (Scheme query : datalog.queries)
            out << "  " << query << "?" << std::endl;

        out << "Domain(" << datalog.domain.size() << "):";
        if (datalog.domain.size() > 0) {
            auto iter = datalog.domain.begin();
            while (iter != datalog.domain.end()) {
                out << std::endl << "  " << *iter++;
            }
        }

        return out;
    }
};


#endif //UNTITLED_PROGRAMDATA_H
