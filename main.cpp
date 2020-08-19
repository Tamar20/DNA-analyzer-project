//
// Created by tamar on 8/18/20.
//

#include "manager.h"
#include "data.h"
#include "cli.h"

int main()
{
    Data d;
    Cli c;

    Manager m(&c, &d);
    m.start(&d);
    m.run();
    m.exit();
    return 0;
}

