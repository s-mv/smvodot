#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

struct EventHandler {
  sf::RenderWindow &window;
  sf::Event e;
  std::unordered_map<
    std::string,
    std::pair<sf::Keyboard::Key, bool>
  > keys = {
    {"up", {sf::Keyboard::Up, false}},
    {"down", {sf::Keyboard::Down, false}},
    {"left", {sf::Keyboard::Left, false}},
    {"right", {sf::Keyboard::Right, false}},
  };

  void run() {
    while (window.pollEvent(e)) {
      switch (e.type) {
      case sf::Event::Closed: {
        // TODO give the dev the option to do whatever on exit
        window.close();
        break;
      }
      case sf::Event::KeyPressed:
      case sf::Event::KeyReleased:
      {
        for (std::pair<std::string, std::pair<sf::Keyboard::Key, bool>> el :
             keys) {
          if (e.key.code == el.second.first) {
            keys[el.first].second = (e.type == sf::Event::KeyPressed);
          }
        }
        break;
      }
      // TODO mouse events
      default:
        break;
      }
    }
  }
  void setKey(std::string ID, sf::Keyboard::Key key) {
    keys[ID] = {key, false};
  }
  void registerKeys(std::unordered_map<std::string, std::pair<sf::Keyboard::Key, bool>> ls) {
    keys.insert(ls.begin(), ls.end());
  }
  bool getKey(std::string ID) { return keys[ID].second; }
};
