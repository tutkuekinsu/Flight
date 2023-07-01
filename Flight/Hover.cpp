#include "Hover.h"

Hover::Hover(float flyDuration, float fuelConsumption) {
    this->flyDuration = flyDuration;
    this->fuelConsumption = fuelConsumption;
}

float Hover::calculateFuel() {
    return flyDuration * fuelConsumption*60 ;
}
