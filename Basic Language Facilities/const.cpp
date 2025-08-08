/*
//Try to modify x1 & x2 and see the compilation output
int x = 5 ;
const int MAX = 12 ;
int &ref_x1 = x ;
const int &ref_x2 = x ;
*/
#include <iostream>
using namespace std;
int main(){
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;


    return 0;
}