//
// Created by tamar on 8/20/20.
//

#include <iostream>
#include "DNAReader.h"
#include "../errors/OpenFileError.h"

DNAReader::DNAReader(std::string name)
{
	name = "dna_files/" + name;
    myfile.open(name.c_str());

    if (!myfile.is_open())
        throw OpenFileError();
}

std::string DNAReader::read()
{
    myfile.seekg (0, std::ios::end);
    int length = (int)myfile.tellg();
    myfile.seekg(0);
    char *output = new char[length+1];
    
    while (!myfile.eof()) {
        myfile >> output;
    }
    
    return output;
}

DNAReader::~DNAReader()
{
    myfile.close();
}

