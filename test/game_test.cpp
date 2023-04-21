#include <gtest/gtest.h>

#include "game_snake.h"
#include "game_welcome.hpp"
#include "render.hpp"

TEST(GameTest, SnakeMove) {
  GameSnake *snake = new GameSnake();
  std::deque<Position> body = {Position(1,1), Position(1,2)};
  snake->setBody(body);
  snake->setDirect(RIGHT);
  snake->move(false);

  EXPECT_EQ(true, snake->contain(Position(2,2)));
}

TEST(GameTest, SnakeEat) {
  GameSnake *snake = new GameSnake();
  std::deque<Position> body = {Position(1,1), Position(1,2)};
  snake->setBody(body);
  snake->setDirect(RIGHT);
}

TEST(GameTest, WelcomeInit) {
  GameWelcome *welcome = new GameWelcome();
  Size size = welcome->getSize();
  EXPECT_EQ(4, size.getRows());
}

TEST(GameTest, ForDebug) {
  GameWelcome *welcome = new GameWelcome();
  Render *render = new Render(Size(200,200));
  render->renderWelcomeWindow(welcome);
}