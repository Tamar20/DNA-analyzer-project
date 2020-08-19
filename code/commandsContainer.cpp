//
// Created by tamar on 8/19/20.
//


#include <fstream>
#include <string>
#include <iostream>
#include "usecase/load.h"
#include "commandsContainer.h"
#include "icommand.h"

std::map<std::string,ICommand*> CommandsContainer::commands; ///???

void CommandsContainer::initMapCommand(Data* dnaData)
{

    commands["load"] = new Load(dnaData);
    //std::cout<<commands["load"]<<std::endl;
}


ICommand* CommandsContainer::getCommand(std::string str)
{
    return commands[str];
}
