//
// Created by tamar on 8/18/20.
//


#ifndef CODE_PARSER_H
#define CODE_PARSER_H


//#include "../commands/icommand.h"
//#include "../dna_data/data.h"

#include <vector>
#include <string>

class Parser
{
public:
    static std::vector<std::string> parser(std::string line);
};


#endif //CODE_PARSER_H
