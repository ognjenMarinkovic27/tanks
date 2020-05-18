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

std::vector<Rigidbody*> PhysicsEngine::getRigidbodies() {
    return rigidbodies;
}

void PhysicsEngine::simulate (bool** terrain, std::vector<int> heightMap, unsigned screenWidth, unsigned screenHeight) {
    for(int i=0;i<screenWidth;i++)
    {
        for(int j=1;j<screenHeight;j++) {
            if(terrain[i][j]==1 && terrain[i][j-1]==0) std::swap(terrain[i][j], terrain[i][j-1]);
        }
    }


    for(auto rb : rigidbodies) {

        int X = (int)round(rb->getPosition().x);
        int Y = (int)round(rb->getPosition().y)-7.5;
        if(terrain[X][Y-1] == 0) rb->enableGravity();
        if(Y<=heightMap[X] && rb->getTravel()) {
                rb->disableGravity();
                if(Y<heightMap[X]) {
                    if(rb->getVelocity().x == 0 || Y-heightMap[X]<25)
                    rb->setPosition(rb->getPosition().x, heightMap[X]);
                    rb->setVelocity(rb->getVelocity().x,0);
                }
                float ang = atan((float)heightMap[X]-heightMap[X+1])*180/3.1415927-90;
                //std::cout << heightMap[X] << " " << heightMap[X+1] << " " << ang <<"\n";
                rb->setRotation(ang);
        }
        if(rb->getGravity())
            rb->addVelocity(0, -gravity);
        rb->setPosition(std::min(std::max(0.0f,rb->getPosition().x+rb->getVelocity().x),(screenWidth-1)*1.0f), std::min(std::max(0.0f,rb->getPosition().y+rb->getVelocity().y),(screenHeight-1)*1.0f));
    }



}
