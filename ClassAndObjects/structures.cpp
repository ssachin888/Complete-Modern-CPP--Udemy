#include<iostream>
struct Point{
    int x;
    int y;
};
//Imagine we have to represent coordinates of two points (start,end).
void drawLine(int x1, int y1, int x2, int y2){
    //This way it not that much explanatory. Instead we use struct to improve
    // it as below function using struct
}
void drawLine(Point start, Point end){
    std::cout<< start.x <<std::endl;
}
int main(){
    return 0;
}