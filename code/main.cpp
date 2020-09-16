//
// Created by tamar on 8/18/20.
//

#include "controller/controller.h"
#include "view/interface/cli.h"

int main()
{
    Data data;
    Cli cli;

    Controller controller(&cli, &data);
    controller.start();
    controller.run();
    controller.exit();
    return 0;
}

