//
// Created by tamar on 8/18/20.
//

#include "save.h"
#include "../../model/read_write/DNAWriter.h"

Save::Save(Data *data) :m_data(data){}

std::string Save::action(const std::vector<std::string>& args)
{
//    if (args.size() > 2)
//        throw INVALID_COMMAND;

    DnaMetaData *metaData = m_data->getByName(args[1]);

    DNAWriter writer(metaData->getName());
    writer.Write(metaData->getDna());

    return "Saved completely.";
}

void Save::help(){}