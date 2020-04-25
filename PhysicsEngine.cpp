#include "PhysicsEngine.h"
#include <iostream>
#include <math.h>

PhysicsEngine::PhysicsEngine() {
}

PhysicsEngine::PhysicsEngine(std::vector<Rigidbody*> rigidbodies) {
    this->rigidbodies = rigidbodies;
}

void PhysicsEngine::addRigidbody(Rigidbody* rb) {
    rigidbodies.push_back(rb);
}

void PhysicsEngine::simulate (bool** t) {

    bool** terrain = t;

    for(auto rb : rigidbodies) {
        rb->addVelocity(0, -gravity);
        if(terrain[(int)round(rb->getPosition().first)][(int)round(rb->getPosition().second)-15] == 1) {rb->setVelocity(0.0, 0.0);}
        rb->setPosition(rb->getPosition().first+rb->getVelocity().first, rb->getPosition().second+rb->getVelocity().second);
    }
}
