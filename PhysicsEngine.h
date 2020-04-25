#include "Rigidbody.h"
#include <vector>

class PhysicsEngine {
    std::vector<Rigidbody*> rigidbodies;

    float gravity = 0.2;
    public:
        PhysicsEngine();
        PhysicsEngine(std::vector<Rigidbody*> rigidbodies);
        void addRigidbody(Rigidbody* rb);
        void simulate(bool** t);
};
