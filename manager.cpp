//
// Created by tamar on 8/18/20.
//

#include <list>
#include "manager.h"
#include "parser.h"
#include "commandsContainer.h"
#include "icli.h"

Manager::Manager(ICli *cli, Data *dnaData): m_cli(cli), m_dnaData(dnaData){}

void Manager::start(Data* dnaData)
{
    std::cout<<"start\n";
    CommandsContainer::initMapCommand(dnaData);
}

void Manager::run()
{
    std::string input = m_cli->input();
    std::list<std::string> parse = Parser::parser(input);
    ICommand* command = CommandsContainer::getCommand("load");
    std::cout << command;
    command->action();
    m_cli->output("output");
}

