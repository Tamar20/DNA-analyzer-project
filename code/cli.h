//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_CLI_H
#define DNA_ANALYZER_PROJECT_CLI_H

#include <iostream>
#include "icli.h"

class Cli : public ICli
{
public:
    /*virtual*/ std::string input(){std::cout<<"input\n";
        return "input";}
    /*virtual */ void output(std::string){std::cout<<"output\n";}

};


#endif //DNA_ANALYZER_PROJECT_CLI_H
