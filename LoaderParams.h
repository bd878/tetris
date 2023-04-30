#pragma once

#include <string>

class LoaderParams
{
public:
  LoaderParams(int x, int y, int width, int height,
    std::string textureID) : _x(x), _y(y), _width(width), _height(height),
    _textureID(textureID)
  {}

  int GetX() const { return _x; }
  int GetY() const { return _y; }
  int GetWidth() const { return _width; }
  int GetHeight() const { return _height; }
  std::string GetTextureID() const { return _textureID; }

private:
  int _x;
  int _y;

  int _width;
  int _height;

  std::string _textureID;
};
