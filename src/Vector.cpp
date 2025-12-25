#include "Vector.hpp"

Vec3::Vec3(float x, float y, float z): x_(x), y_(y), z_(z) {}

float Vec3::getX() const {
    return x_;
}
float Vec3::getY() const {
    return y_;
}
float Vec3::getZ() const {
    return z_;
}
void Vec3::setZ(float newZ) {
    z_ = newZ;
}

float Vec3::dotProduct(const Vec3 &q2Vec) const {
  return x_ * q2Vec.x_ + y_ * q2Vec.y_ + z_ * q2Vec.z_;
}

Vec3 Vec3::crossProduct(const Vec3 &q2Vec) const {
  // a x b = (c_x, c_y, c_z)
  float c_x = y_ * q2Vec.z_ - z_ * q2Vec.y_;
  float c_y = z_ * q2Vec.x_ - x_ * q2Vec.z_;
  float c_z = x_ * q2Vec.y_ - y_ * q2Vec.x_;
  return Vec3(c_x, c_y, c_z);
}

Vec3 Vec3::multiplyByScalar(float scalarMultiplier) const {
  return Vec3(scalarMultiplier * x_, scalarMultiplier * y_,
              scalarMultiplier * z_);
}

