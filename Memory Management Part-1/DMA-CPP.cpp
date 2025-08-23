#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void Malloc(){
    int *p = (int*)calloc(1, sizeof(int));
    if(p == NULL){
        printf("Fail to allocate memory\n");
        return;
    }
    *p = 5;
    printf("%d", *p);
    free(p);
    p = NULL;
    free(p);
}
void New(){
    int *p = new int;
    *p = 6;
    std::cout<<"value: "<<*p<<std::endl;
    delete p;
    p = nullptr;
}
int main(){
    New();
}
