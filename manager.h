//
// Created by tamar on 8/18/20.
//

#ifndef CODE_MANAGER_H
#define CODE_MANAGER_H

#include <cstddef>
#include <map>
#include <string>
#include <iostream>

class ICli;
class Data;

class Manager
{
public:
	Manager(ICli* cli, Data* dnaData);
	void run();
	void start(Data* dnaData);
	void exit(){std::cout<<"exit\n";}
private:
	ICli* m_cli;
	Data* m_dnaData;
};


#endif




