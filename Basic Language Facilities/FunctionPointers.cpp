#include <iostream>
using namespace std;
void print(int a, char c){
    for(int i = 0; i < a; i++){
        cout<<c<<ends;
    }
    cout<<endl;
}
void EndProgram(){
    cout<<"Calling function using atexist"<<endl;
}
int main(){
    atexit(EndProgram); // This is a function which is called at the end of the program
    print(5,'#');
    void (*fptr)(int,char) = &print;
    (*fptr)(8,'@');
    fptr(5,'+');
    cout<<"End of the main program"<<endl;
}