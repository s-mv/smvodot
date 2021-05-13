#pragma once

struct Engine {
  sf::Clock gameClock;

  int width, height;
  int FPS = 69;
  double dt; // deltatime in seconds
  
  std::unordered_map<std::string, Scene*> scenes;
  std::string currentScene;
  
  sf::RenderWindow window;
  EventHandler handler { .window = window };
  
  void start() {
    dt = 1 / FPS;
    window.create(sf::VideoMode(width, height), "hello");

    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);

    scenes[currentScene]->init();
    while(window.isOpen()) {
      dt = gameClock.restart().asSeconds();
      handler.run();
      window.clear();
      scenes[currentScene]->run(dt);
      window.display();
    }
  }
};

