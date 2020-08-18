//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_DNAMETADATA_H
#define DNA_ANALYZER_PROJECT_DNAMETADATA_H
#include "dna/dna.h"

class DnaMetaData
{
public:
    size_t getId(){return 1;}
    std::string getName(){return "sari";}
    DnaSequence* getDna(){char * a = "ATTG"; return new DnaSequence(a);}

private:
    size_t m_id;
    std::string m_name;
    DnaSequence* m_dna;

};


#endif //DNA_ANALYZER_PROJECT_DNAMETADATA_H
