//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_SAVE_H
#define DNA_ANALYZER_PROJECT_SAVE_H

#include <iostream>
#include "../iCommand.h"
#include "../data.h"


class Save: public ICommand
{
public:
    Save(Data*);
    /*virtual*/ void action(){std::cout<<"in Save\n";}
    /*virtual*/ void help();
};

#endif //DNA_ANALYZER_PROJECT_SAVE_H
