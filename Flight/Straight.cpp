#include "Straight.h"

Straight::Straight(float distance, float speed, float fuelConsumption) {
    this->distance = distance;
    this->speed = speed;
    this->fuelConsumption = fuelConsumption;
}

float Straight::calculateFuel() {
    return fuelConsumption * (distance / speed);
}
