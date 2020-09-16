//
// Created by tamar on 8/18/20.
//

#include "new.h"
#include "../../../model/dna_data/data.h"
#include <sstream>

New::New(Data* data) : m_data(data) {}

std::string New::action(const std::vector<std::string>& args)
{
    std::string seq = args[1];
    std::string name = m_data->getNameDnaByArgs(args);
    m_data->NewDna(name, seq);

    std::stringstream ss;
    ss << "[" << m_data->getId() << "] " << name << ": " << seq << std::endl;
    return ss.str();
}
