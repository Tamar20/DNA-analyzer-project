//#include <cstddef>
//#include <map>
//#include <string>
//#include <iostream>
//#include "dna.h"
//#include "icli.h"
//#include "dnaMetaData.h"
//#include "data.h"
//#include "iCommand.h"
//#include "new.h"
//
//
//
//class DnaMetaData;
//
//class DnaData;
//
//class Parser;
//
//
//
//class Manager
//{
//public:
//	Manager(ICli* cli,DnaData* dnaData,Parser* parser){
//	m_cli=cli;
//	m_dnaData=dnaData;
//	m_parser=parser;
//	}
//	void run(){
//	 //std::string str=m_cli->input();
//	 ICommand* command = m_parser->parser(m_cli->input()) ;
//	 command->action();
//	 m_cli->output("output");
//	}
//	void start(){std::cout<<"start\n";}
//	void exit(){std::cout<<"exit\n";}
//private:
//	ICli* m_cli;
//	DnaData* m_dnaData;
//	Parser* m_parser;
//};
//

#include <cstddef>
#include <map>
#include <string>
#include <iostream>
#include "dna/dna.h"
#include "icli.h"
#include "data.h"

class Manager
{
public:
    Manager(ICli* cli, Data* dnaData);
    void run();
    void start(){std::cout<<"start\n";}
    void exit(){std::cout<<"exit\n";}
private:
    ICli* m_cli;
    Data* m_dnaData;
};











