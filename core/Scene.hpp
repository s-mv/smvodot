#pragma once
#include "./Node.hpp"

struct Scene {
  Node root;
  void init() { root.init(); }
  void run(double dt) { root.run(dt); };
};

