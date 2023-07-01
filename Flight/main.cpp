#include <iostream>
#include <vector>
#include "Hover.h"
#include "Rising.h"
#include "Descending.h"
#include "Straight.h"

int main() {
    std::vector<Movement*> movements;
    int choice = 0;
    float flyDuration, fuelConsumption, startAltitude, endAltitude, speed, distance;

    while (true) {
        std::cout << "Please select a maneuver type (1: Hover, 2: Rising, 3: Descending, 4: Straight, 5: Completed): "<< std::endl;
        std::cin >> choice;

        if (choice == 5) {
            float totalFuel = 0.0;
            for (Movement* movement : movements) {
                totalFuel += movement->calculateFuel();
            }
            std::cout << "Total required amount of fuel for this mission: " << totalFuel << " kg" << std::endl;
            
            // Clean up dynamically created objects for the completed mission
            for (Movement* movement : movements) {
                delete movement;
            }

            // Clear the movements vector for the next mission
            movements.clear();

            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter airtime and fuel consumption for Hovering: "<< std::endl;
                std::cin >> flyDuration >> fuelConsumption;
                if (flyDuration<0||fuelConsumption<0) { 
                    std::cout<<"The hover time or the fuel consumption value specific to this maneuver cannot be less than 0."<<std::endl;
                }
                else{
                    movements.push_back(new Hover(flyDuration, fuelConsumption));
                }
                break;

            case 2:
                std::cout << "Enter the start altitude, finish altitude, speed, and fuel consumption for Rising: "<< std::endl;
                std::cin >> startAltitude >> endAltitude >> speed >> fuelConsumption;
                if (speed<=0||fuelConsumption<0||startAltitude>endAltitude) { 
                    std::cout<<"In the ascending manoeuvre; speed<=0, fuel consumption cannot be less than 0 and the last altitude cannot be less than the first altitude."<<std::endl;
                }
                else{
                movements.push_back(new Rising(startAltitude, endAltitude, speed, fuelConsumption));
                }
                break;
                
            case 3:
                std::cout << "Enter start altitude, finish altitude, speed and fuel consumption for Descending: "<< std::endl;
                std::cin >> startAltitude >> endAltitude >> speed >> fuelConsumption;
                if (speed<=0||fuelConsumption<0||startAltitude<endAltitude) { 
                    std::cout<<"In descending manoeuvre; speed<=0, fuel consumption cannot be less than 0 and last altitude cannot be higher than first altitude."<<std::endl;
                }
                else{
                movements.push_back(new Descending(startAltitude, endAltitude, speed, fuelConsumption));
                }
                break;

            case 4:
                std::cout << "Enter distance, speed and fuel consumption for Straight flight: "<< std::endl;
                std::cin >> distance >> speed >> fuelConsumption;
                if (speed<=0||fuelConsumption<0||distance<0) { 
                    std::cout<<"The hover time or the fuel consumption value specific to this maneuver cannot be less than 0."<<std::endl;
                }
                else{
                movements.push_back(new Straight(distance, speed, fuelConsumption));                }
                break;

            default:
                std::cout << "Invalid selection! Please try again."<< std::endl;
                break;
        }
    }

    return 0;
}


//g++ main.cpp Hover.cpp Rising.cpp Descending.cpp Straight.cpp -o main