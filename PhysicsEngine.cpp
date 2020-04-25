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

void PhysicsEngine::simulate (bool** t, std::vector<int> hm) {

    bool** terrain = t;
    std::vector<int> heightMap = hm;

    for(auto rb : rigidbodies) {
        rb->addVelocity(0, -gravity);
        int X = (int)round(rb->getPosition().x);
        int Y = (int)round(rb->getPosition().y)-7.5;
        if(Y<=heightMap[X]) {
                if(Y<heightMap[X]) {
                    rb->setPosition(rb->getPosition().x, heightMap[X]);
                }
                rb->setVelocity(rb->getVelocity().x, 0.0);
                float ang = atan((float)heightMap[X]-heightMap[X+1])*180/3.1415927-90;
                std::cout << heightMap[X] << " " << heightMap[X+1] << " " << ang <<"\n";
                rb->setRotation(ang);
        }
        rb->setPosition(rb->getPosition().x+rb->getVelocity().x, rb->getPosition().y+rb->getVelocity().y);


    }
}
