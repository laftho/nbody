#ifndef __VECTOR_H_INCLUDED
#define __VECTOR_H_INCLUDED

class Vector3D {
  public:
    long double x;
    long double y;
    long double z;
    Vector3D () {};
    Vector3D (long double _x, long double _y, long double _z) : x(_x), y(_y), z(_z) {};
    Vector3D operator + (const Vector3D&);
    Vector3D operator - (const Vector3D&);
    Vector3D operator / (const long double);
    long double distance(const Vector3D&);
};

#endif // __VECTOR_H_INCLUDED
