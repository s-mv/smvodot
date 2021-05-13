#pragma once
#include "../../core/Node.hpp"
#include "../../utils/Vector.hpp"

struct Node2D : public Node {
  Vector pos;
  Node2D(Vector pos, std::vector<Node*> children) : Node(children), pos(pos) {}
};
