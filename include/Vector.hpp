#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vec3 {
public:
  Vec3(float x, float y, float z);
  float getX() const;
  float getY() const;
  float getZ() const;
  void setZ(float newZ);
  float dotProduct(const Vec3 &q2Vec) const;
  Vec3 crossProduct(const Vec3 &q2Vec) const;
  Vec3 multiplyByScalar(float scalarMultipler) const;
  Vec3 rotateVector(const Vec3 &q2Vec) const;

private:
  float x_;
  float y_;
  float z_;
};

#endif
