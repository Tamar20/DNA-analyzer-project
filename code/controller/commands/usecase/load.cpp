//
// Created by tamar on 8/18/20.
//

#include <sstream>

#include "load.h"
#include "../../read_write/DNAReader.h"
#include "../../../model/dna_data/data.h"
#include "../../commands_container.h"
#include "../../errors/InvalidCommand.h"

Load::Load(Data *data, ICommand* creation):m_data(data), m_creation(creation) {}

std::string Load::action(const std::vector<std::string>& args)
{
	if (args.size() < 2 || args.size() > 3 || (args.size() == 3 && args[2][0] != '@'))
    {
        throw InvalidCommand();
    }
    
    DNAReader reader(args[1]);
    std::vector<std::string> updatedArgs = args;
    
    /*if (args.size() == 3)
    	updatedArgs[2].erase(updatedArgs.begin());*/
    
    updatedArgs[1] = reader.read();

    return m_creation->action(updatedArgs);
}

std::string Load::help()
{
    return "load:\n Loads the sequence from the file\n"
           "<>: parameters []: optional parameters.\n"
           "load <file_name>  [@<sequence_name>]";
}
