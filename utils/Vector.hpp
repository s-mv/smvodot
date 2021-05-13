#pragma once
#include <math.h>

struct Vector {
  float x, y;
  Vector() : x{0}, y{0} {}
  Vector(float X, float Y) : x{X}, y{Y} {}
  Vector operator+(Vector const &vec) { return Vector(x + vec.x, y + vec.y); }
  void operator+=(Vector const &vec) { *this = *this + vec; }
  Vector operator-(Vector const &vec) { return Vector(x - vec.x, y - vec.y); }
  void operator-=(Vector const &vec) { *this = *this - vec; }
  Vector operator*(Vector const &vec) { return Vector(x * vec.x, y * vec.y); }
  void operator*=(Vector const &vec) { *this = *this * vec; }
  Vector operator*(float const &mag) { return Vector(x * mag, y * mag); }
  void operator*=(float const &mag) { *this = *this * mag; }
  Vector operator/(Vector const &vec) { return Vector(x / vec.x, y / vec.y); }
  void operator/=(Vector const &vec) { *this = *this / vec; }
  Vector operator/(float const &mag) { return Vector(x / mag, y / mag); }
  void operator/=(float const &mag) { *this = *this / mag; }
  inline float mag() { return sqrt(pow(x, 2) + pow(y, 2)); }
  inline float dir() { return atan2(y, x); } // radians
};
