#ifndef QUATERNION_HPP
#define QUATERNION_HPP
#include "Vector.hpp"

class Quaternion {
public:
  // Multiple constructors
  Quaternion(float w, Vec3 q1);
  // Quaternion from Euler Angles
  Quaternion(float theta_x, float theta_y, float theta_z);
  Quaternion eulerToQuat(float theta_x, float theta_y, float theta_z);
  Vec3 rotate(const Vec3 &transformVec) const;

private:
  float w_;
  Vec3 q1_;
};

#endif
