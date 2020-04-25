#include <utility>

class Rigidbody {
    std::pair<float, float> position;
    std::pair<float, float> velocity;
    public:
        Rigidbody();
        Rigidbody(float x, float y);
        void addVelocity(float x, float y);
        void setVelocity(float x, float y);
        void setPosition(float x, float y);
        std::pair<float, float> getPosition();
        std::pair<float, float> getVelocity();
};
