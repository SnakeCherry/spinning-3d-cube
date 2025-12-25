#include "Cube.hpp"
#include "Quaternion.hpp"
#include <vector>

Cube::Cube(float cubeWidth, float incrementSpeed, float thetaX, float thetaY,
           float thetaZ, Screen &screen, int distanceFromCam)
    : cubeWidth_(cubeWidth), incrementSpeed_(incrementSpeed), thetaX_(thetaX),
      thetaY_(thetaY), thetaZ_(thetaZ), screen_(screen),
      horizontalOffset_(-2 * cubeWidth), reciprocalZ_(0.0f),
      distanceFromCam_(distanceFromCam) {}

void Cube::setReciprocalZ_(const float reciprocalZ) {
  reciprocalZ_ = reciprocalZ;
  return;
}

void Cube::setAngles(float thetaX, float thetaY, float thetaZ) {
  thetaX_ = thetaX;
  thetaY_ = thetaY;
  thetaZ_ = thetaZ;
}

void Cube::placeIntoBuffer_(float xProj, float yProj, int ch, char *buffer,
                            float *zBuffer) {
  int x = static_cast<int>(xProj);
  int y = static_cast<int>(yProj);
  float screenWidth = screen_.getScreenWidth();
  float screenHeight = screen_.getScreenHeight();
  if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
    return;

  int idx = x + y * screenWidth;
  if (reciprocalZ_ > zBuffer[idx]) {
    zBuffer[idx] = reciprocalZ_;
    buffer[idx] = ch;
  }

  return;
}

std::vector<float> Cube::calculateProjectionPoints_(Vec3 cubePoint) {
  // 40.0f is arbitrary. Try different values to see what works
  float K1 = 40.0f;
  Quaternion rotationQ = {thetaX_, thetaY_, thetaZ_};
  Vec3 rotatedVec = rotationQ.rotate(cubePoint);
  rotatedVec.setZ(rotatedVec.getZ() + distanceFromCam_);
  setReciprocalZ_(1 / rotatedVec.getZ());

  float xProjected = (screen_.getScreenWidth() / 2 + horizontalOffset_ +
                      K1 * reciprocalZ_ * rotatedVec.getX() * 2);
  float yProjected =
      (screen_.getScreenHeight() / 2 + K1 * reciprocalZ_ * rotatedVec.getY());

  std::vector<float> projectionPoints;
  projectionPoints.push_back(xProjected);
  projectionPoints.push_back(yProjected);

  return projectionPoints;
}

void Cube::calculateForSurface_(Vec3 cubePoint, int ch, char *buffer,
                                float *zBuffer) {
  std::vector<float> projectionPoints = calculateProjectionPoints_(cubePoint);
  placeIntoBuffer_(projectionPoints[0], projectionPoints[1], ch, buffer,
                   zBuffer);
}

void Cube::displayCube(char *buffer, float *zBuffer) {
  for (float cubeX = -cubeWidth_; cubeX < cubeWidth_;
       cubeX += incrementSpeed_) {
    for (float cubeY = -cubeWidth_; cubeY < cubeWidth_;
         cubeY += incrementSpeed_) {
      calculateForSurface_(Vec3{cubeX, cubeY, -1 * cubeWidth_}, '@', buffer,
                           zBuffer);
      calculateForSurface_(Vec3{cubeWidth_, cubeY, cubeX}, '$', buffer,
                           zBuffer);
      calculateForSurface_(Vec3{-cubeWidth_, cubeY, -cubeX}, '~', buffer,
                           zBuffer);
      calculateForSurface_(Vec3{-cubeX, cubeY, cubeWidth_}, '#', buffer,
                           zBuffer);
      calculateForSurface_(Vec3{cubeX, -cubeWidth_, -cubeY}, ';', buffer,
                           zBuffer);
      calculateForSurface_(Vec3{cubeX, cubeWidth_, cubeY}, '+', buffer,
                           zBuffer);
    }
  }
}
