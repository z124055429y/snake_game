#include <curses.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "game.h"

static void alarm_action(int);

Game *game;

Game::Game()
{
    srand(time(NULL));
    game = this;
    mWindow.push_back(WINDOW_WELCOME);

    WINDOW *window = initscr();
    int x,y;
    getmaxyx(stdscr,y,x);

    pRender = new Render(Size(y, x));
    pInitializer = new Initializer();
    pController = new Controller();

    startTimer();
}

Game::~Game()
{
    delete pInitializer;
    delete pRender;
    delete pController;

    stopTimer();
    endwin();
}

void Game::startTimer()
{
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 500 * 1000;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 500 * 1000;

    if (setitimer(ITIMER_REAL, &timer, NULL) != 0)
    {
        perror("setitimer");
        ::exit(0);
    }

    if (signal(SIGALRM, alarm_action) != 0)
    {
        perror("signal");
        ::exit(0);
    }
}

void Game::stopTimer()
{
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
}

void Game::render() {
    int top = mWindow.back();
    switch (top)
    {
    case WINDOW_WELCOME:
        pRender->renderWelcomeWindow(pInitializer->getWelcome());
        break;
    case WINDOW_GAME:
        pRender->renderGameWindow(pInitializer, pInitializer->getMap(), pInitializer->getWall(), pInitializer->getSnake(), pInitializer->getFood(), pInitializer->getStatus());
        break;
    }
    
    pRender->refresh();
}

void Game::run()
{
    char ch;
    while (true)
    {
        ch = getch();
        int cmd = pController->generateCommand(mWindow.back(), ch);
        bool exit = handle(cmd, ch);
        if (exit) break;
    }
    refresh();
}

bool Game::handle(int cmd, char op) {
    switch (cmd)
    {
    case CMD_QUIT:
        return true;
    case CMD_START:
        mWindow.push_back(WINDOW_GAME);
        break;
    case CMD_MOVE:
        GameSnake *snake = pInitializer->getSnake();
        switch (op)
        {
        case 'w':
            snake->setDirect(UP);
            break;
        case 's':
            snake->setDirect(DOWN);
            break;
        case 'a':
            snake->setDirect(LEFT);
            break;
        case 'd':
            snake->setDirect(RIGHT);
            break;
        }
        break;
    }
    return false;
}


void alarm_action(int signo)
{
    game->render();
}