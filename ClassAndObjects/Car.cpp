#include "Car.h"
#include <iostream>
Car::Car()
{
}
Car::Car(float amount)
{
    fuel = amount;
}
Car::~Car()
{
    std::cout<<"Destructor is called:"<<std::endl;
}
void Car::fillFuel(float amount)
{
    fuel = amount;
}

void Car::accelerate()
{
    speed++;
    fuel-=0.5f;
}

void Car::brake()
{
    speed = 0;
}

void Car::addPassengers(int count)
{
    passengers = count;
}

void Car::dashBoard()
{
    std::cout<< "Fuel: "<<fuel <<std::endl;
    std::cout<< "Speed: "<<speed <<std::endl;
    std::cout<< "Passengers: "<<passengers <<std::endl;
}