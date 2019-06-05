#ifndef __ENTITY_H_INCLUDED
#define __ENTITY_H_INCLUDED

class Vector3D;

#include "vector.h"

class Entity {
  public:
    int id;
    Vector3D *velocity;
    Vector3D *position;
    Vector3D *accumulate;
    long double mass;
    long double density;
    long double volume;
    bool resolved;
    Entity() {
      resolved = false;
    };
    void add(const Vector3D&);
    void resolve();
};

#endif // __ENTITY_H_INCLUDED
