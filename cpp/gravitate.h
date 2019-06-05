#ifndef __GRAVITATE_H_INCLUDED
#define __GRAVITATE_H_INCLUDED

class Vector3D;
class Entity;

#define GRAVITY 6.6740831e-6 // 6.6740831e-11

Vector3D gravitate(const Entity&, const Entity&);

#endif // __GRAVITATE_H_INCLUDED
