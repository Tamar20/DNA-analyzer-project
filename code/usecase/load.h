//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_LOAD_H
#define DNA_ANALYZER_PROJECT_LOAD_H

#include "../iCommand.h"
#include "../data.h"
#include <iostream>

class Load: public ICommand
{
public:
    Load(Data*);
    /*virtual*/ void action(){std::cout<<"in Load\n";}
    /*virtual*/ void help();
} ;



#endif //DNA_ANALYZER_PROJECT_LOAD_H
