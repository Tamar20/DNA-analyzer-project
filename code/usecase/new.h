//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_NEW_H
#define DNA_ANALYZER_PROJECT_NEW_H

#include "../iCommand.h"
#include "../data.h"

class New: public ICommand
{

public:
    New(Data,std::string name);
    /*virtual*/ void action(){std::cout<<"in New\n";}
    /*virtual*/ void help();

private:
    static size_t s_id;
    static size_t s_name;
};
q

#endif //DNA_ANALYZER_PROJECT_NEW_H
