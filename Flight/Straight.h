#include "Movement.h"

class Straight : public Movement {
private:
    float distance; // x
    float speed; //v
    float fuelConsumption; 

public:
    Straight(float distance, float speed, float fuelConsumption);

    float calculateFuel() override;
};