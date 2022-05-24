#include <iostream>
#include "Quateronion.h"

int main() {
    std::cout << "Vector!" << std::endl;

    Vector3 v(0,1,0);

    //rotation
    Vector3 axis(1,0,0);

    Vector3 rotatedVector = v.rotateVector(90,axis);


    return 0;
}
