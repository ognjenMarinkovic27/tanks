#include <utility>

class PhysicsObject {
    std::pair<float, float> position;
    std::pair<float, float> velocity;
    public:
        PhysicsObject();
        PhysicsObject(float x, float y);
        void addVelocity(float x, float y);
        void setVelocity(float x, float y);
        void move();
        float getX();
        float getY();
};
