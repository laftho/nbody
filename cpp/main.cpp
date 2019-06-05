#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "vector.h"
#include "entity.h"
#include "gravitate.h"

#define nbodies 10000

Entity** generateEntities() {
  static Entity* entities [nbodies];

  std::srand(1);

  for(int n = 0; n < nbodies; n++) {
    Entity* entity = new Entity();

    long double mass = std::rand() % (int)1e4 + 1e7;
    long double px = std::rand() % (int)1e6 * (std::rand() % 10 > 5 ? -1 : 1);
    long double py = std::rand() % (int)1e6 * (std::rand() % 10 > 5 ? -1 : 1);
    long double pz = std::rand() % (int)1e6 * (std::rand() % 10 > 5 ? -1 : 1);

    entity->position = new Vector3D(px, py, pz);
    entity->velocity = new Vector3D(0, 0, 0);
    entity->accumulate = new Vector3D(0, 0, 0);
    entity->mass = mass;

    entities[n] = entity;
  }

  return entities;
}

void frame(Entity** entities) {
  for(int n = 0; n < nbodies; n++) {
    Entity* entity = entities[n];
    for(int s = 0; s < nbodies; s++) {
      *entity->accumulate = *entity->accumulate + gravitate(*entity, *entities[s]);
    }
  }

  for(int n = 0; n < nbodies; n++) {
    entities[n]->resolve();
  }
}

int main() {
  std::cout << "Generate ";

  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

  Entity** entities = generateEntities();

  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

  auto gentime = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

  std::cout << gentime << " milliseconds\n";

  int sum = 0;
  int avg = 0;

  for(int i = 0; i < 100; i++) {

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    frame(entities);

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    sum += millis;

    avg = sum / (i + 1);

    std::cout << "Frame [ " << millis << " / " << avg << " ] milliseconds\n";
  }
}
