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

private:
  float w_;
  Vec3 q1_;

  Vec3 rotate(const Vec3 &transformVec) const;
  Quaternion conjugate_();

  // What do we need to do?
  //
  /**
   * We take in a vector, change it into a quaternion
   * Apply first transformation to it
   */
};

#endif
