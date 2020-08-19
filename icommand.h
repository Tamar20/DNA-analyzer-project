//
// Created by tamar on 8/18/20.
//

#ifndef CODE_ICOMMAND_H
#define CODE_ICOMMAND_H


class ICommand
{
public:
    virtual void action()=0;
    virtual void help()=0;
};


#endif //CODE_ICOMMAND_H
