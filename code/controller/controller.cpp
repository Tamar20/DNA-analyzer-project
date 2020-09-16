#include "controller.h"
#include "../view/parser.h"
#include "commands_container.h"


Controller::Controller(ICli *cli, Data *dnaData): m_cli(cli), m_dnaData(dnaData)
{
    CommandsContainer::init_map_command(m_dnaData);
}

void Controller::run()
{
    while (1)
    {
        std::string input = m_cli->input();
        std::vector<std::string> parse = Parser::parser(input);

        if (parse[0] == "exit")
        {
            break;
        }
        ICommand* command = CommandsContainer::get_command(parse[0]);

        if (!command)
        {
            std::cout << parse[0] << ": command not found" << std::endl;
        }
        else
        {
            std::string output = command->action(parse);
            m_cli->output(output);
        }

    }

}

