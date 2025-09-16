#include "Car.h"
int main(){
    Car::showCount();
    //Car car;
    const Car car(5);
    //car.fillFuel(6);
    car.dashBoard();
    Car c1, c2;
    //car.dashBoard();
    Car::showCount();
}