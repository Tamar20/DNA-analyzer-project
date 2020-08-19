//
// Created by tamar on 8/19/20.
//

#ifndef CODE_COMMANDSCOINTAINER_H
#define CODE_COMMANDSCOINTAINER_H


#include <list>
#include <string>
#include <map>

class ICommand;
class Data;

class CommandsContainer
{
public:
    static void initMapCommand(Data*);
    static ICommand* getCommand(std::string);
private:
    static std::map<std::string,ICommand*> commands;
};

#endif //CODE_COMMANDSCOINTAINER_H
