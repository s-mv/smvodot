# smvodot
Badly written C++ Godot, by smv

## What is this?
Godot-like framework in C++, still under development. Just something I made for fun, it may not be efficient.

## Docs/Wiki
Okay, so the docs are not ready yet as this was something more of a passtime, but here's some really really basic sample code.
```cpp
#include <SMV/smvodot/smv.hpp> // placed in the includes folder for me
// Node inheritence, yeah Node is a struct
struct Greeter : public Node {
  Greeter(std::vector<Node*> children = {}) : Node(children) {}
  void init () override {
    printf("Hello, world!");
  }
};
  
struct Game : public smvodot::Engine {
  Game(std::unordered_map<std::string, Scene*> scenes = {}) : Engine(scenes) {}
  void init () override {
    printf("wow I modified the engine");
    Engine::init();
 }
};

int main () {
  Game game ({
      {"test",
        new Scene {
          .root = Node({
            new Greeter,
            new Greeter,
            new Greeter({
              new Node
            })
          })
        }
      }
  });
  return 0;
}
```

## Why does this use SFML?
I was too lazy and wanted to test it quickly. :P
