//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_ICLI_H
#define DNA_ANALYZER_PROJECT_ICLI_H
#include <string>


class ICli
{
public:
    virtual std::string input() = 0;
    virtual void output(std::string) = 0;

};

#endif //DNA_ANALYZER_PROJECT_ICLI_H
