//
// Created by tamar on 9/14/20.
//

#include "DNAWriter.h"
#include "../errors/OpenFileError.h"

DNAWriter::DNAWriter(std::string name)
{
    name = "dna_files/" + name + ".rawdna";
    myfile.open(name.c_str());
    
    if (!myfile.is_open())
        throw OpenFileError();
}

/*void Write(const SharedPtr<IDnaSequence> other)
{
	for (size_t i = 0; i < other->length(); ++i)
        myfile << (other)[i];

}*/

void DNAWriter::Write(const DnaSequence* other) //??
{
    for (size_t i = 0; i < other->length(); ++i)
        myfile << other[i];
}

DNAWriter::~DNAWriter()
{
    myfile.close();
}
