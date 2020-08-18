//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_DATA_H
#define DNA_ANALYZER_PROJECT_DATA_H
#include <map>
#include "dnaMetaData.h"


class Data
{
public:
    DnaMetaData* getByName(std::string){return new DnaMetaData();}
    DnaMetaData* getById(size_t){return new DnaMetaData();}
private:
    std::map<std::string,DnaMetaData*> m_names;
    std::map<size_t,DnaMetaData*> m_ids;

};


#endif //DNA_ANALYZER_PROJECT_DATA_H
