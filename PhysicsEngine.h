#include "Rigidbody.h"
#include <vector>

class PhysicsEngine {
    std::vector<Rigidbody*> rigidbodies;

    float gravity = 2;
    public:
        PhysicsEngine();
        PhysicsEngine(std::vector<Rigidbody*> rigidbodies);
        std::vector<Rigidbody*> getRigidbodies();
        void addRigidbody(Rigidbody* rb);
        void simulate(bool** t, std::vector<int> hm, unsigned screenWidth, unsigned screenHeight);
};
