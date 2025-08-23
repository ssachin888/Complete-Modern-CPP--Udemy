#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void NewArrays(){
    // int *p = new int[5]{1,2,3,4,5};
    int *p = new int[5];
    for(int i = 0;i<5;i++){
        p[i] = i;
    }

    delete []p;
    p = nullptr;
}
void Strings(){
    char * p = new char[4];
    strcpy(p,"C++");
    std::cout<< p<< std::endl;
    delete []p;
}
int main(){
    //NewArrays();
    Strings();
}
