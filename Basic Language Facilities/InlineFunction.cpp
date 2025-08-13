#include<iostream>
using namespace std;
extern "C" int square(int a){
    return a * a;
}

// Defining a macro
//#define square(x) x*x
int main(){
    //cout<<square(5)<<endl;
    int val = 5;
    int res = square(val + 1);
    cout << res << endl;
    return 0;
} 