//
// Created by tamar on 8/18/20.
//

#ifndef CODE_LOAD_H
#define CODE_LOAD_H


#include "../icommand.h"
//#include "../../dna_data/data.h"
class Data;

class Load: public ICommand
{
public:
    Load(Data* data, ICommand* creation);
    /*virtual*/ std::string action(const std::vector<std::string>& );
    /*virtual*/ std::string help();

private:
    Data *m_data;
    ICommand* m_creation;
} ;


#endif //CODE_LOAD_H
