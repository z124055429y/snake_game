#include <curses.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "game.h"

static void alarm_action(int);
static void initTerminalSize();
Game *game;

Game::Game()
{
    game = this;
    WINDOW *window = initscr();
    int x,y;
    getmaxyx(stdscr,y,x);
    startTimer();

    pRender = new Render(Size(y, x));
    welcome = new Welcome();
}

Game::~Game()
{
    delete pRender;
    delete welcome;
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
        exit(0);
    }

    if (signal(SIGALRM, alarm_action) != 0)
    {
        perror("signal");
        exit(0);
    }
}

void Game::stopTimer()
{
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) != 0)
    {
        perror("setitimer");
        exit(0);
    }

    if (signal(SIGALRM, alarm_action) != 0)
    {
        perror("signal");
        exit(0);
    }
}

void Game::render() {
    pRender->renderWelcomeWindow(welcome);
    
    pRender->refresh();
}

void Game::run()
{
    char ch;
    while (true)
    {
        ch = getch();
    }
    refresh();
}

void alarm_action(int signo)
{
    game->render();
}