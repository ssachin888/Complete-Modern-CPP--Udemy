#include "Car.h"
#include <iostream>
int Car::totalCount = 0; // Even we dont intialise it to 0, it will be automatially intialised to 0;
Car::Car()
{
    ++totalCount;
}
Car::Car(float amount)
{
    ++totalCount;
    fuel = amount;
}
Car::~Car()
{
    --totalCount;
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
void Foo(const Car &car){

}
void Car::addPassengers(int passengers)
{
    this->passengers = passengers;
    Foo(*this);
}

void Car::dashBoard() const
{
    // ++fuel; menaing this->fuel++;
    std::cout<< "Fuel: "<<fuel <<std::endl;
    std::cout<< "Speed: "<<speed <<std::endl;
    std::cout<< "Passengers: "<<passengers <<std::endl;
}

void Car::showCount()
{
    std::cout<< "Total cars: "<<totalCount <<std::endl;
}
