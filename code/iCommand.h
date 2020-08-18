//
// Created by tamar on 8/18/20.
//

#ifndef DNA_ANALYZER_PROJECT_ICOMMAND_H
#define DNA_ANALYZER_PROJECT_ICOMMAND_H


class ICommand
{
public:
    virtual void action()=0;
    virtual void help();

};

#endif //DNA_ANALYZER_PROJECT_ICOMMAND_H
