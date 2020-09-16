//
// Created by tamar on 9/16/20.
//

#ifndef CODE_IDNASEQUENCE_H
#define CODE_IDNASEQUENCE_H


#include "DnaSequence.h"

//???
enum Nucleotide: char { A = 'A', a = 'A', C = 'C', c = 'C', G = 'G', g = 'G', T = 'T', t = 'T'};
///???
class IDnaSequence
{
public:
    virtual ~IDnaSequence(){}
    virtual size_t length() const = 0;
    virtual Nucleotide& operator[](size_t) = 0;
};



#endif //CODE_IDNASEQUENCE_H
