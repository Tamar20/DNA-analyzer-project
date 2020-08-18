//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_PARSER_H
#define DNA_ANALYZER_PROJECT_PARSER_H

#include <string>
#include <list>


class Icommand;


class Parser
{
public:
    static std::list<std::string> parser(std::string line);
};

#endif //DNA_ANALYZER_PROJECT_PARSER_H
