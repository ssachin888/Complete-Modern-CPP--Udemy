#include<iostream>
using namespace std;
/*
The problem with swapping 
void swap(int a, int b){
    int temp = a;
    a = b;
    b= temp;
}
*/
/*
Using Pointers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b= temp;
}
*/
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b= temp;
}
void printbyPTR(int *ptr){
    if(ptr != nullptr)
        cout<<"Pointer value: " << *ptr << endl;
}
void printbyREF(int &ptr){
    cout<<"Pointer value: " << ptr << endl;
}
int main(){
    int x = 5;
    // printbyPTR(&x);
    // printbyPTR(nullptr);
    // printbyREF(x);


    
    //printbyREF(nullptr);
}