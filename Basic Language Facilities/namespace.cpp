#include<iostream>
namespace AVG{
    float calculate(float x, float y){
        return (x + y) / 2;
    }
}
namespace Basic{
    float calculate(float x, float y){
        return x + y;
    }
}
int main(){
    // 1st way
    //using namespace AVG;
    // calculate(3.3f,2.2f);

    // 2nd way
    // using AVG::calculate;
    // calculate(1.1f,2.2f);
    
    //3rd way
    //AVG::calculate(2.1f, 5.1f);

    using namespace AVG;
    calculate(3.3f,2.2f);
    //using namespace Basic;
    //calculate(1.1f,2.2f);
    Basic::calculate(1.1f,2.2f);

    return 0;
}