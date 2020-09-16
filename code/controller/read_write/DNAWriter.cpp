//
// Created by tamar on 9/14/20.
//

#include "DNAWriter.h"

DNAWriter::DNAWriter(std::string name)
{
    name += ".rawdna";
    myfile.open(name.c_str());
    if (!myfile.is_open())
        throw std::domain_error("We couldn't open the file.");
}


void DNAWriter::Write(const DnaSequence* other)
{
    for (size_t i = 0; i < other->length(); ++i)
        myfile << (other)[i];
}


DNAWriter::~DNAWriter()
{
    myfile.close();
}