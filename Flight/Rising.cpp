#include "Rising.h"

Rising::Rising(float startAltitude, float endAltitude, float risingSpeed, float fuelConsumption) {
    this->startAltitude = startAltitude;
    this->endAltitude = endAltitude;
    this->risingSpeed = risingSpeed;
    this->fuelConsumption = fuelConsumption;
}

float Rising::calculateFuel() {
    float elapsedAltitude = endAltitude - startAltitude; // Calculate elapsed time
    return fuelConsumption * (elapsedAltitude / risingSpeed);
}
