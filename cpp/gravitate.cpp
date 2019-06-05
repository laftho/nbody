#include "vector.h"
#include "entity.h"
#include "gravitate.h"

Vector3D gravitate (const Entity& entity, const Entity& satellite) {
  Vector3D force (0, 0, 0);
  
  if (entity.id == satellite.id) {
    return force;
  }
  
  long double distance = entity.position->distance(*satellite.position);
  
  if (distance <= 0) {
    return force;
  }
  
  Vector3D deltaFrom = *satellite.position - *entity.position;
  
  long double gravitation = GRAVITY * ((entity.mass * satellite.mass) / (distance * distance));
  
  if (gravitation == 0) {
    return force;
  }
  
  force.x = (deltaFrom.x * gravitation) / distance;
  force.y = (deltaFrom.y * gravitation) / distance;
  force.z = (deltaFrom.z * gravitation) / distance;
  
  return force;
}
