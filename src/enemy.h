
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
public:
  Enemy();
  virtual ~Enemy();
  void setPosition(sf::Vector2f pos);
  sf::Vector2f getPosition();
  void setTexture(sf::Texture &texture);
  void draw(sf::RenderTarget &target);
  void move();
  void takeDamage(int damage);
  bool isDead();

protected:
  sf::Sprite sprite;
  bool dead;
  int health;
  sf::Texture texture;
};

class Drone : public Enemy {
public:
  Drone();
  void move();

private:
  bool moving;
};

class Turret : public Enemy {
public:
  Turret();
};