#ifndef QUATERNION_HPP
#define QUATERNION_HPP

class Quaternion {
public:
  Quaternion(float w, float x, float y, float z, float theta);
  ~Quaternion() = default;

private:
  float w_;
  float x_;
  float y_;
  float z_;
  float theta_;

  float dotProduct_(const Quaternion& q2);
  float multiplyReal_(const Quaternion& q2);

  // What do we need to do?
  //
  /**
     * We take in a vector, change it into a quaternion
     * Apply first transformation to it
     */ 
};

#endif
