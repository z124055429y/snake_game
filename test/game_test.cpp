#include <gtest/gtest.h>

#include "snake.h"
#include "game_welcome.hpp"
#include "render.hpp"

// Demonstrate some basic assertions.
TEST(GameTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(GameTest, SnakeMove) {
  Snake *snake = new Snake();
  std::deque<Position> body = {Position(1,1), Position(1,2)};
  snake->setBody(body);
  snake->setDirect(RIGHT);
  snake->move();

  EXPECT_EQ(true, snake->contain(Position(2,2)));
}

TEST(GameTest, SnakeEat) {
  Snake *snake = new Snake();
  std::deque<Position> body = {Position(1,1), Position(1,2)};
  snake->setBody(body);
  snake->setDirect(RIGHT);
}

TEST(GameTest, WelcomeInit) {
  GameWelcome *welcome = new GameWelcome();
  Size size = welcome->getSize();
  EXPECT_EQ(4, size.getRows());
}

TEST(GameTest, Debug) {
  GameWelcome *welcome = new GameWelcome();
  Render *render = new Render(Size(200,200));
  render->renderWelcomeWindow(welcome);
}