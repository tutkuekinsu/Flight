#include "Movement.h"

class Hover : public Movement {
private:
    float flyDuration; // Airtime
    float fuelConsumption; 

public:
    Hover(float flyDuration, float fuelConsumption);


    float calculateFuel() override;
};
