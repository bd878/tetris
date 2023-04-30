#pragma once

#include <cmath>

class Vector2D
{
public:
  Vector2D() : _x(0), _y(0) {}
  Vector2D(float x, float y) : _x(x), _y(y) {}

  float GetX() { return _x; }
  float GetY() { return _y; }

  void SetX(float x) { _x = x; }
  void SetY(float y) { _y = y; }

  float Length() { return std::sqrt(_x*_x + _y*_y); }

  Vector2D operator+(const Vector2D& v2) const
  {
    return Vector2D(_x + v2._x, _y + v2._y);
  }

  friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
  {
    v1._x += v2._x;
    v1._y += v2._y;

    return v1;
  }

  Vector2D operator*(float scalar)
  {
    return Vector2D(_x * scalar, _y * scalar);
  }

  Vector2D& operator*=(float scalar)
  {
    _x *= scalar;
    _y *= scalar;

    return *this;
  }

  Vector2D operator-(const Vector2D& v2) const
  {
    return Vector2D(_x - v2._x, _y - v2._y);
  }

  friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
  {
    v1._x -= v2._x;
    v1._y -= v2._y;

    return v1;
  }

  Vector2D operator/(float scalar)
  {
    return Vector2D(_x / scalar, _y / scalar);
  }

  Vector2D& operator/=(float scalar)
  {
    _x /= scalar;
    _y /= scalar;

    return *this;
  }

  void normalize()
  {
    float l = Length();
    if (l > 0)
    {
      (*this) *= 1 / l;
    }
  }

private:
  float _x;
  float _y;
};
