//
// Created by tamar on 8/18/20.
//

#include "../../read_write/DNAReader.h"
#include "../../../model/dna_data/data.h"
#include <sstream>
#include "load.h"

Load::Load(Data *data, ICommand* creation):m_data(data), m_creation(creation) {}

std::string Load::action(const std::vector<std::string>& args)
{
    DNAReader reader(args[1]);
    std::vector<std::string> updatedArgs = args;
    updatedArgs[1] = reader.read();
//    std::string name = m_data->getNameDnaByArgs(args);
//    m_data->NewDna(name, reader.read());
//
//    std::stringstream ss;
//    ss << "[" << m_data->getByName(name)->getId() << "] " << name <<": " << *(m_data->getByName(name)->getDna());
//    return ss.str();
    return m_creation->action(updatedArgs);
}

void Load::help(){}
