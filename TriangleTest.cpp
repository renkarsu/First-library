#include"hello.h"
#include"triangle.h"

//g++ -std=c++17 -Wall --pedantic-errors TriangleTest.cpp -o triangle
int main(){
    //test 'hello.h'
    std::cout << "Test Hello()" << std::endl;
    brahman::Hello();
    std::cout << std::endl;

    //test 'area.h'
    constexpr brahman::Triangle<double> tri(2.5, 4.2, 5.0);

    std::cout << "Input data: " << tri.GetAB() << " " << tri.GetBC() << " " << tri.GetCA() << std::endl << std::endl;

    std::cout << "Test GetAB(), GetBC(), GetCA()" << std::endl;
    std::cout << "tri.GetAB(): " << tri.GetAB() << std::endl;
    std::cout << "tri.GetBC(): " << tri.GetBC() << std::endl;
    std::cout << "tri.GetCA(): " << tri.GetCA() << std::endl << std::endl;

    std::cout << "Test GetArea()" << std::endl;
    std::cout << "tri.GetArea(): " << tri.GetArea() << std::endl << std::endl;

    std::cout << "Test GetShape()" << std::endl;
    std::cout << "tri.GetShape(): " << tri.GetShape() << std::endl << std::endl;

    std::cout << "Test PrintCondition()" << std::endl;
    std::cout << tri;
}