#pragma once
#include <iostream>
#include <vector>
struct Node {
  std::vector<Node *> children;
  // Node() = default;
  Node(std::vector<Node *> children = {}) : children(children) {}
  virtual void init() {
    for (Node *child : children) {
      child->init();
    }
  }
  virtual void run(double dt) {
    for (Node *child : children) {
      child->run(dt);
    }
  }
};
