#pragma once
#include "../smv.hpp"
#include "../core/Node.hpp"

// just a "template" node

struct TestNode : public Node {
  void run(double dt) override {
    Node::run(dt);
  }
};
