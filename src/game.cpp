#include "game.h"

void Game::pollEvents() {
  while (this->window.pollEvent(this->ev)) {
    if (this->ev.type == sf::Event::Closed)
      this->window.close();
    else if (this->ev.type == sf::Event::KeyPressed &&
             this->ev.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
}
const bool Game::running() const { return window.isOpen(); }

void Game::playerUpdatePosition() { this->player->playerMovement(); }

void Game::playerRender() { this->window.draw(this->player->GetSprite()); }

// IMPORTANTA CRITICA -
void Game::update() {

  while (this->window.pollEvent(this->ev)) {
    if (this->ev.type == sf::Event::Closed) {
      this->window.close();
    } else if (ev.type == sf::Event::KeyReleased) {
      this->player->playerIdle();
    } else if (ev.type == sf::Event::KeyPressed)
      this->playerUpdatePosition();
  }
}

// IMPORTANTA CRITICA - FUNCTIA MARE DE RENDER/AFISARE
void Game::render() {
  this->window.clear(); // stergem frame-ul trecut
  window.draw(bg);
  this->playerRender();
  this->window.display(); // afisam frame-ul
}

// FUNCTIE DE INITIALIZARE FEREASTRA PRINCIPALA.
void Game::initWindow() {
  this->window.create(VideoMode(1200, 474), "Unreal Engine 5",
                      Style::Close | Style::Titlebar);
  this->window.setFramerateLimit(144);
}

// FUNCTIE DE INITIALIZARE PLAYER PRINCIPAL
void Game::initPlayer() { this->player = new Player(0, 300, 1.70, 1.70); }

void Game::initBackground() {
  if (!background.loadFromFile("backgorundfinal.jpg",
                               IntRect(0, 0, 1200, 474))) {
    throw;
  }
  this->bg.setTexture(this->background);
}

// CONSTRUCTOR GAME, FOLOSESTE FUNCTIILE CELE 2 DE INITIALIZARE
Game::Game() {
  this->initWindow();
  this->initBackground();
  this->initPlayer();
}

Game::~Game() { delete player; }