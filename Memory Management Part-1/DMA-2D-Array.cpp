#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void TwoDArrays(){
    int *p1 = new int[3];
    int *p2 = new int[3];
    int **pData = new int *[2]; // **pData is array of pointers
                                // *[2] rows of 2d array
    pData[0] = p1; // 1st row
    pData[1] = p2; // 2nd row

    //Accessing the elements
    pData[0][1] = 2;

    delete []p1; // delete []pData[0]
    delete []p2; // delete []pData[1]
    delete []pData;

}
int main(){
    int data[2][3]={
        1,2,3,  
        4,5,6
    }; // 1,2,3,4,5,6
    data[0,1];
    //TwoDArrays();
}
