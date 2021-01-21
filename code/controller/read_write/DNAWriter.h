//
// Created by tamar on 9/14/20.
//

#ifndef CODE_DNAWRITER_H
#define CODE_DNAWRITER_H


#include <fstream>
#include "../../model/dna/DnaSequence.h" // I ??
//#include "../../shared_ptr.h" //???

class DNAWriter
{
public:
    DNAWriter(std::string);
    void Write(const DnaSequence* other); // I ???
    //void Write(const SharedPtr<IDnaSequence> other);
    
    ~DNAWriter();

private:
    // composition
    std::ofstream myfile;
};




#endif //CODE_DNAWRITER_H
