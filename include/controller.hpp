#if !defined(_CONTROLLER_H_)
#define _CONTROLLER_H_

#define WINDOW_WELCOME 1
#define WINDOW_GAME 2

#define CMD_IGN 0
#define CMD_QUIT 1
#define CMD_START 2
#define CMD_MOVE 3

class Controller
{
private:
    /* data */
public:
    Controller();
    ~Controller();
    int generateCommand(int window, char op);
};



#endif // _CONTROLLER_H_
