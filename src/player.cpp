#include "player.h"
PlayerState currentState = PlayerState::IDLE;
Player::Player(float PosX, float PosY, float ScaleX, float ScaleY) {
  this->frame = 0;
  this->moving = false;
  this->frameIdle = 0;
  this->initTexture();
  this->initSprite();
  this->initTimer();
  this->setIdleAnimation();
  this->setRunAnimation();
  this->setRunBackwardsAnimation();
  this->position.x = PosX;
  this->position.y = PosY;
  this->sprite.setPosition(position);
  if (ScaleX > 0 && ScaleY > 0) {
    this->sprite.scale(ScaleX, ScaleY);
  }
}

void Player::initTexture() {
  if (!this->texture.loadFromFile("idle-2.png", IntRect(0, 0, 71, 67))) {
    throw;
  }
}

void Player::initTimer() { this->animationTimer.restart(); }
void Player::initSprite() { this->sprite.setTexture(this->texture); }

void Player::SetMovement(float x, float y) { sprite.move(x, y); }

void Player::SetNewFrame(Texture texture) {
  this->texture = texture;
  this->sprite.setTexture(this->texture);
}

void Player::setRunAnimation() {
  RunAnimation = new Texture[8];
  if (!(*RunAnimation).loadFromFile("run-1.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 1)).loadFromFile("run-2.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 2)).loadFromFile("run-3.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 3)).loadFromFile("run-4.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 4)).loadFromFile("run-5.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 5)).loadFromFile("run-6.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 6)).loadFromFile("run-7.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunAnimation + 7)).loadFromFile("run-8.png", IntRect(0, 0, 71, 67)))
    throw;
}

void Player::setRunBackwardsAnimation() {
  RunBackwardsAnimation = new Texture[8];
  if (!(*RunBackwardsAnimation)
           .loadFromFile("run-1-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 1))
           .loadFromFile("run-2-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 2))
           .loadFromFile("run-3-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 3))
           .loadFromFile("run-4-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 4))
           .loadFromFile("run-5-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 5))
           .loadFromFile("run-6-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 6))
           .loadFromFile("run-7-backwards.png", IntRect(0, 0, 71, 67)))
    throw;

  if (!(*(RunBackwardsAnimation + 7))
           .loadFromFile("run-8-backwards.png", IntRect(0, 0, 71, 67)))
    throw;
}

void Player::setIdleAnimation() {
  IdleAnimation = new Texture[4];
  if (!(*IdleAnimation).loadFromFile("idle-1.png", IntRect(0, 0, 71, 67)))
    throw;
  if (!(*(IdleAnimation + 1)).loadFromFile("idle-2.png", IntRect(0, 0, 71, 67)))
    throw;
  if (!(*(IdleAnimation + 2)).loadFromFile("idle-3.png", IntRect(0, 0, 71, 67)))
    throw;
  if (!(*(IdleAnimation + 3)).loadFromFile("idle-4.png", IntRect(0, 0, 71, 67)))
    throw;
}

void Player::playerMovement() {

  if (frame > 7) {
    frame = 0;
  }

  if (Keyboard::isKeyPressed(Keyboard::A)) {
    if (sprite.getPosition().y - 2 < 470 - 71) {
      this->moving = true;
      currentState = PlayerState::MOVING_LEFT;
      sprite.move(-5.f, 0.f);
      if (this->animationTimer.getElapsedTime().asSeconds() >= 0.09f) {

        SetNewFrame(*(RunBackwardsAnimation + frame));
        this->animationTimer.restart();
      }
      frame++;
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::D)) {
    sprite.move(5.f, 0.f);
    this->moving = true;
    currentState = PlayerState::MOVING_RIGHT;
    if (this->animationTimer.getElapsedTime().asSeconds() >= 0.09f) {

      SetNewFrame(*(RunAnimation + frame));
      this->animationTimer.restart();
    }
    frame++;
  }
  if (Keyboard::isKeyPressed(Keyboard::W)) {
    if (sprite.getPosition().y + 2.f > 350 - 71) {
      this->moving = true;
      currentState = PlayerState::MOVING_UP;
      sprite.move(0.f, -5.f);
      if (this->animationTimer.getElapsedTime().asSeconds() >= 0.09f) {

        SetNewFrame(*(RunAnimation + frame));
        this->animationTimer.restart();
      }
      frame++;
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::S)) {

    if (sprite.getPosition().y - 2 < 420 - 71) {
      this->moving = true;
      currentState = PlayerState::MOVING_DOWN;
      sprite.move(0.f, 5.f);
      if (this->animationTimer.getElapsedTime().asSeconds() >= 0.8f) {

        SetNewFrame(*(RunAnimation + frame));
        this->animationTimer.restart();
      }
      frame++;
    }
  }
}

void Player::playerIdle() {
  if (frameIdle >= 3)
    frameIdle = 0;

  if (currentState != PlayerState::IDLE) {
    currentState = PlayerState::IDLE;
    this->moving = false;

    SetNewFrame(*(IdleAnimation + 1));
  }
  frameIdle++;
}

Player::~Player() {
  delete[] RunAnimation;
  delete[] IdleAnimation;
}
