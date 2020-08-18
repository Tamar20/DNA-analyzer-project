#include "manager.h"
#include "cli.h"

int main()
{
    Data d;
    Cli c;

    Manager m(&c, &d);
    m.start();
    m.run();
    m.exit();
    return 0;
}