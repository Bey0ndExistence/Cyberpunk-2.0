#include "game.h"
#include "player.h"

#include <SFML/Graphics.hpp>

int main() {

  Game game;

  while (game.running()) {
    game.update();
    game.render();
  }

  return 0;
}