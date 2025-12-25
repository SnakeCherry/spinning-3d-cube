#import "Quaternion.hpp"

Quaternion::Quaternion(float w, float x, float y, float z, float theta): w_(w), x_(x), y_(y), z_(z), theta_(theta) {} 

float Quaternion::dotProduct_(const Quaternion& q2) {
    return x_*q2.x_ + y_*q2.y_ + z_*q2.z_;
}

float Quaternion::multiplyReal_(const Quaternion& q2) {
    float wProd = w_ * q2.w_;
    float q1q2DotProduct = dotProduct_(q2);
    return wProd - q1q2DotProduct;
}


