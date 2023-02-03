#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
// Clasa jucator
class Player {
private:
  int frame;
  int frameIdle;
  bool moving;
  Clock animationTimer;
  Sprite sprite;
  Vector2f position;
  Vector2f velocity;
  Texture texture;
  Texture *RunAnimation;
  Texture *IdleAnimation;
  Texture *RunBackwardsAnimation;

public:
  Player(float PosX, float PosY, float ScaleX = 1, float ScaleY = 1);
  virtual ~Player();
  Sprite &GetSprite() { return sprite; }
  void initTexture();
  void initSprite();
  void initTimer();
  void playerMovement();

  bool checkPlayerPosition();
  void SetMovement(float x, float y);
  void SetNewFrame(Texture texture);
  Texture *GetRunAnimation() { return RunAnimation; }
  Texture *GetIdleAnimation() { return IdleAnimation; }
  void setRunAnimation();
  void setIdleAnimation();
  void setRunBackwardsAnimation();
  void playerIdle();
};
// player.h
enum class PlayerState {
  IDLE,
  MOVING_LEFT,
  MOVING_RIGHT,
  MOVING_UP,
  MOVING_DOWN
};
extern PlayerState currentState;