#pragma once
class Car{
private:  
    float fuel{0};
    float speed{0};
    int passengers{0};
    static int totalCount; // We need to define it outside the class. Preferably in Car.cpp
    // We can even initialise array and pointer
    int arr[5] = {1,2,3,4,5};
    int *p{};
    // When we are non-static data member intialisation auto will not work
    // auto i = 5;
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
    static void showCount();
};