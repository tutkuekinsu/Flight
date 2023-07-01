#include "Movement.h"

class Descending : public Movement {
private:
    float startAltitude; 
    float endAltitude; 
    float descendingSpeed; 
    float fuelConsumption; 

public:
    Descending(float startAltitude, float endAltitude, float descendingSpeed, float fuelConsumption);

    float calculateFuel() override;
};
