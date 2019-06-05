const GRAVITY = 6.6740831e-6; //6.6740831e-11;

export function gravitate(entity, satellite) {
  if (entity.id === satellite.id) {
    return;
  }

 // if (entity.mass <= 0 || satellite.mass <= 0) {
 //   return;
 // }

  const distance = entity.distance(satellite);

  if (distance <= 0) {
    return;
  }

  const delta = entity.positionDeltaFrom(satellite);

  const gravitation = GRAVITY * ((entity.mass * satellite.mass) / (distance ** 2));

  if (gravitation === 0) {
    return;
  }

  const force = {
    x: (delta.x * gravitation) / distance,
    y: (delta.y * gravitation) / distance,
    z: (delta.z * gravitation) / distance
  };

  entity.add(force.x, force.y, force.z);
}
