//
// Created by tamar on 6/1/20.
//

#ifndef DNA_INVALIDDNA_H
#define DNA_INVALIDDNA_H



#include "DnaException.h"

class InvalidDna: public DnaException
{
public:
    InvalidDna();
};


InvalidDna::InvalidDna(): DnaException("Invalid DNA sequence") {}


#endif //DNA_INVALIDDNA_H
