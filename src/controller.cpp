#include "controller.hpp"


Controller::Controller()
{
}

Controller::~Controller()
{
}

int Controller::generateCommand(int window, char op) {
    if (window == WINDOW_WELCOME) {
        switch (op)
        {
        case 'q':
            return CMD_QUIT;
        case 's':
            return CMD_START;
        }
    } else if(window == WINDOW_GAME) {
        switch (op)
        {
        case 'q':
            return CMD_QUIT;
        case 'w':
        case 'a':
        case 's':
        case 'd':
            return CMD_MOVE; 
        default:
            break;
        }
    }
    return CMD_IGN;
}
