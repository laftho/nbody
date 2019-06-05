import { Entity } from './entity.mjs';
import { gravitate } from './gravitate.mjs';

function random(min, max) {
  return Math.floor(Math.random() * ((Math.floor(max) - Math.ceil(min)) + Math.ceil(min)));
}

function generateEntities(nbodies = 10000) {
  const entities = [];
  
  for(let n = 0; n < nbodies; n++) {
    const mass = random(1e4, 1e7); // random(1e4, 1e8);
    const entity = new Entity({
      id: n,
      mass: mass,
      volume: Math.ceil(mass / 1e3) + 1,
      position: {
        x: random(0, 1e6) * (random(0, 10) > 5 ? -1 : 1),
        y: random(0, 1e6) * (random(0, 10) > 5 ? -1 : 1),
        z: random(0, 1e6) * (random(0, 10) > 5 ? -1 : 1)
      }
    });
    
    entities.push(entity);
  }
  
  return entities;
}

function frame(entities = []) {
  for(const entity of entities) {
    for(const satellite of entities) {
      gravitate(entity, satellite);
    }
  }
  
  for(const moment of entities) {
    moment.resolve();
  }
}

const startGenerate = process.hrtime.bigint();

const entities = generateEntities();

const endGenerate = process.hrtime.bigint();

console.log(`Generate ${(endGenerate - startGenerate) / BigInt(1e6)} milliseconds`);

let sum = BigInt(0);
let avg = BigInt(0);

for(let i = 0; i < 100; i++) {
  const start = process.hrtime.bigint();

  frame(entities);

  const end = process.hrtime.bigint();
  
  const millis = (end - start) / BigInt(1e6);
  sum += millis;
  
  avg = sum / BigInt(i + 1);

  console.log(`Frame [ ${millis} / ${avg} ] milliseconds`);
}
