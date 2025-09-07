#include "Car.h"
#include <iostream>
Car::Car()
{
    std::cout<<"Constructor is called:"<<std::endl;
    fuel = 0;
    speed = 0;
    passengers = 0;
}
Car::Car(float amount)
{
    fuel = amount;
    speed = 0; // Dont forget to intialise another component otherwise they will be undefined
    passengers = 0;
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