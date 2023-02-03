#include "player.h"
#include <SFML/Graphics.hpp>

class Game {
private:
  sf::RenderWindow window;
  sf::Event ev;
  void initWindow();
  void initPlayer();
  void initBackground();
  Player *player;
  Texture background;
  Sprite bg;

public:
  Game();
  const bool running() const;
  void pollEvents();
  void update();
  void render();
  void playerUpdatePosition();
  void playerRender();
  void initTimer();
  virtual ~Game();
};