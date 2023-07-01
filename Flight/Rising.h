#include "Movement.h"

class Rising : public Movement {
private:
    float startAltitude; 
    float endAltitude; 
    float risingSpeed; 
    float fuelConsumption; 

public:
    Rising(float startAltitude, float endAltitude, float risingSpeed, float fuelConsumption);

    float calculateFuel() override;
};
