/*
Implement the following functions using pointer arguments only

int Add(int *a, int *b) ;    //Add two numbers and return the sum

void AddVal(int *a, int *b, int *result); 
//Add two numbers and return the sum through the third pointer argument

void Swap(int *a, int *b) ;  //Swap the value of two integers

void Factorial(int *a, int *result);     
//Generate the factorial of a number and return that through the second pointer argument
*/

#include <iostream>
using namespace std;
int Add(int *a, int *b){
    return *a + *b;
}
void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
}
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Factorial(int *a, int *result){
    int z = *a, fact=1;
    while(z>0){
        fact = fact*z;
        z--;
    }
    *result = fact;
}
int main(){
    int x = 5, y = 3, result;

    cout << "Add: " << Add(&x, &y) << endl;

    AddVal(&x, &y, &result);
    cout << "AddVal result: " << result << endl;

    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    Swap(&x, &y);
    cout << "After Swap:  x = " << x << ", y = " << y << endl;

    Factorial(&x, &result);
    cout << "Factorial of x: " << result << endl;
    return 0;
}