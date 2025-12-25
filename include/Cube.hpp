#ifndef CUBE_HPP
#define CUBE_HPP
#include "Screen.hpp"
#include "Vector.hpp"
#include <vector>

class Cube {
public:
  Cube(float cubeWidth, float incrementSpeed, float thetaX, float thetaY,
       float thetaZ, Screen &screen, int distanceFromCam);
  void displayCube(char *buffer, float *zBuffer);
  void setAngles(float thetaX, float thetaY, float thetaZ);

private:
  float cubeWidth_;
  float incrementSpeed_;
  float thetaX_;
  float thetaY_;
  float thetaZ_;
  Screen screen_;
  float horizontalOffset_;
  float reciprocalZ_;
  int distanceFromCam_;

  std::vector<float> calculateProjectionPoints_(Vec3 cubePoint);
  void setReciprocalZ_(const float reciprocalZ);
  void placeIntoBuffer_(float xProj, float yProj, int ch, char *buffer,
                        float *zBuffer);
  void calculateForSurface_(Vec3 cubePoint, int ch, char *buffer,
                            float *zBuffer);
};
#endif
