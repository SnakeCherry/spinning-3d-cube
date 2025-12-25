#ifndef CUBE_HPP
#define CUBE_HPP
#include "Quaternion.hpp"


class Cube {
public:
  Cube(float cubeWidth, float incrementSpeed);
  // https://github.com/tarantino07/cube.c/blob/70393184924406941d34785542874e3c6d558807/cube.c
private:
  float cubeWidth_;
  float incrementSpeed_; 
  float thetaX_;
  float thetaY_;
  float thetaZ_;
  void calculateForSurface_(Vec3 &cubePoint, int ch) const; 

  

};
#endif
