#pragma once
class Car{
private:  
    float fuel;
    float speed;
    int passengers;
public:
    Car();
    Car(float amount);
    ~Car();
    void fillFuel(float amount); // These functions can be defined in the class itself.
                                // In that case it will be automatically inline.
                                // Mostly we define functions in a separate source file.
    void accelerate();
    void brake();
    void addPassengers(int count);
    void dashBoard();

};