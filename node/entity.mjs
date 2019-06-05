export class Entity {
  constructor({
    id = null,
    mass = 0,
    position = { x: 0, y: 0, z: 0 },
    velocity = { x: 0, y: 0, z: 0 },
    density = 0,
    volume = 0,
    accumulate = { x: 0, y: 0, z: 0 }
  } = {}) {
    this.id = id;
    this.mass = mass;
    this.position = position;
    this.velocity = velocity;
    this.density = density;
    this.volume = volume;
    this.accumulate = accumulate;
  }
  
  positionDeltaTo(entity) {
    return {
      x: this.position.x - entity.position.x,
      y: this.position.y - entity.position.y,
      z: this.position.z - entity.position.z
    };
  }

  positionDeltaFrom(entity) {
    return {
      x: entity.position.x - this.position.x,
      y: entity.position.y - this.position.y,
      z: entity.position.z - this.position.z
    };
  }

  distance(entity) {
    const delta = this.positionDeltaTo(entity);

    return Math.sqrt(
      delta.x * delta.x +
      delta.y * delta.y +
      delta.z * delta.z
    );
  }
  
  add(x, y, z) {
    this.accumulate.x += x;
    this.accumulate.y += y;
    this.accumulate.z += z;
  }
  
  resolve() {
    if (this.resolved) {
      return;
    }
    
    /*const accumulate = { x: 0, y: 0, z: 0 };

    for(const force of this.forces) {
      accumulate.x += force.x;
      accumulate.y += force.y;
      accumulate.z += force.z;
    }
    */

    this.velocity.x += this.accumulate.x / this.mass;
    this.velocity.y += this.accumulate.y / this.mass;
    this.velocity.z += this.accumulate.z / this.mass;

    this.position.x += this.velocity.x;
    this.position.y += this.velocity.y;
    this.position.z += this.velocity.z;

    this.resolved = true;
  }
}
