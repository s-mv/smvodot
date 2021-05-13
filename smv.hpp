#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include "./core/EventHandler.hpp"
#include "./core/Node.hpp"
#include "./core/Scene.hpp"

// TODO: use OpenGL smh
namespace smvodot {

namespace gl {

void init() {
  
}

void drawRect(int x, int y, int w, int h) {

}
void fillRect() {

}
void drawLine() {}
void drawPoint() {}
void drawEllipse() {}
void fillEllipse() {}
void drawImage() {}
void drawText() {}
void fillText() {}

}

struct Engine {
  Engine(std::unordered_map<std::string, Scene*> scenes = {}) : scenes(scenes) {}
  sf::Clock gameClock;

  int width, height;
  int FPS = 69;
  double dt; // deltatime in seconds
  
  std::unordered_map<std::string, Scene*> scenes;
  std::string currentScene;
  
  sf::RenderWindow window;
  EventHandler handler { .window = window };
  
  virtual void init() {
    dt = 1 / FPS;
    window.create(sf::VideoMode(width, height), "hello");

    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);

    scenes[currentScene]->init();
  }

  virtual void start() {
    while(window.isOpen()) {
      dt = gameClock.restart().asSeconds();
      handler.run();
      window.clear();
      scenes[currentScene]->run(dt);
      window.display();
    }
  }
};

}
