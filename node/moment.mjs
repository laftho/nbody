export class Moment {
  constructor({
    id = null,
    epoch = 0,
    entity = null,
    forces = [],
    resolved = false,
    accumulate = { x: 0, y: 0, z: 0 }
  } = {}) {
    this.id = id;
    this.epoch = 0;
    this.entity = entity;
    this.forces = forces;
    this.resolved = resolved;
    this.accumulate = accumulate;
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

    this.entity.velocity.x += this.accumulate.x / this.entity.mass;
    this.entity.velocity.y += this.accumulate.y / this.entity.mass;
    this.entity.velocity.z += this.accumulate.z / this.entity.mass;

    this.entity.position.x += this.entity.velocity.x;
    this.entity.position.y += this.entity.velocity.y;
    this.entity.position.z += this.entity.velocity.z;

    this.resolved = true;
  }
}
