#import "Quaternion.hpp"

// General form for Quaternion
Quaternion::Quaternion(float w, Vec3 q1) : w_(w), q1_(q1) {}

// Helper function to initialise q (rotation quaternion)
Quaternion Quaternion::eulerToQuat(float theta_x, float theta_y,
                                   float theta_z) {
  float sinX = sin(theta_x / 2);
  float sinY = sin(theta_y / 2);
  float sinZ = sin(theta_z / 2);
  float cosX = cos(theta_x / 2);
  float cosY = cos(theta_y / 2);
  float cosZ = cos(theta_z / 2);
  float w = (sinX * sinY * sinZ + cosX * cosY * cosZ);

  float xCoord = (sinX * cosY * cosZ - cosX * sinY * sinZ);
  float yCoord = (cosX * sinY * cosZ + sinX * cosY * sinZ);
  float zCoord = (cosX * cosY * sinZ - sinX * sinY * cosZ);
  Vec3 q1 = Vec3{xCoord, yCoord, zCoord};
  return Quaternion(w, q1);
}

// Quaternion from EULERIAN Angles
Quaternion::Quaternion(float theta_x, float theta_y, float theta_z)
    : Quaternion(eulerToQuat(theta_x, theta_y, theta_z)) {}

Vec3 Quaternion::rotate(const Vec3 &origVec) const {
  Vec3 qCrossV = q1_.crossProduct(origVec);
  Vec3 multipledByRotationScalar = qCrossV.multiplyByScalar(2 * w_);
  Vec3 qCrossPrev = q1_.crossProduct(qCrossV);
  float rotatedX = origVec.getX() + multipledByRotationScalar.getX() +
                   2 * (qCrossPrev.getX());
  float rotatedY = origVec.getY() + multipledByRotationScalar.getY() +
                   2 * (qCrossPrev.getY());
  float rotatedZ = origVec.getZ() + multipledByRotationScalar.getZ() +
                   2 * (qCrossPrev.getZ());
  return Vec3{rotatedX, rotatedY, rotatedZ};
}
