#include <iostream>
using namespace std;
void show(int a);
void show(int a, int b = 0); // ❌ Ambiguity if called with one argument
int main(){
     show(5);
     return 0;
}