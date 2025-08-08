/*
Implement the following functions

void Add(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments
*/
#include <iostream>
using namespace std;
void Add(int a,int b, int &result){
    result = a + b;
}
void Factorial(int a, int &result){
    result = 1;
    for(int i = 1 ;i<= a;i++){
        result = result* i;
    }
}
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

}
int main(){
    int x = 5, y = 3, result;

    Add(x, y, result);
    cout << "Add: " << result << endl;

    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    Swap(x, y);
    cout << "After Swap:  x = " << x << ", y = " << y << endl;

    Factorial(x, result);
    cout << "Factorial of x: " << result << endl;
    return 0;
}