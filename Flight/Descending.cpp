#include "Descending.h"

Descending::Descending(float startAltitude, float endAltitude, float descendingSpeed, float fuelConsumption) {
    this->startAltitude = startAltitude;
    this->endAltitude = endAltitude;
    this->descendingSpeed = descendingSpeed;
    this->fuelConsumption = fuelConsumption;
}

float Descending::calculateFuel() {
    float elapsedAltitude =  startAltitude - endAltitude; //Calculate elapsed time
    return fuelConsumption * (elapsedAltitude / descendingSpeed);
}
