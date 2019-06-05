#include <math.h>
#include "vector.h"

Vector3D Vector3D::operator + (const Vector3D& param) {
  Vector3D vector;
  
  vector.x = x + param.x;
  vector.y = y + param.y;
  vector.z = z + param.z;
  
  return vector;
}

Vector3D Vector3D::operator - (const Vector3D& param) {
  Vector3D vector;
  
  vector.x = x - param.x;
  vector.y = y - param.y;
  vector.z = z - param.z;
  
  return vector;
}

Vector3D Vector3D::operator / (const long double param) {
  Vector3D vector;
  
  vector.x = x / param;
  vector.y = y / param;
  vector.z = z / param;
  
  return vector;
}

long double Vector3D::distance (const Vector3D& param) {
  Vector3D deltaTo = *this - param;
  
  return sqrt(deltaTo.x * deltaTo.x + deltaTo.y * deltaTo.y + deltaTo.z * deltaTo.z);
}
