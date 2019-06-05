#include "vector.h"
#include "entity.h"

void Entity::add (const Vector3D& param) {
  *accumulate = *accumulate + param;
}

void Entity::resolve () {
  if (resolved) {
    return;
  }
  
  *position = *velocity + (*accumulate / mass);
  
  resolved = true;
}
