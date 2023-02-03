#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy() {

  if (!this->texture.loadFromFile("poza-inamic.png",
                                  sf::IntRect(0, 0, 71, 67))) {
    throw;
  }
  dead = false;
  this->sprite.setTexture(this->texture);
}

void Enemy::setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

sf::Vector2f Enemy::getPosition() { return sprite.getPosition(); }

void Enemy::setTexture(sf::Texture &texture) { sprite.setTexture(texture); }

void Enemy::draw(sf::RenderTarget &target) { target.draw(sprite); }

bool Enemy::isDead() { return dead; }

Drone::Drone() { moving = false; }

void Enemy::takeDamage(int damage) {
  health -= damage;
  if (health <= 0) {
    dead = true;
  }
}
