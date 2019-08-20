#include"hello.h"
#include"triangle.h"

//g++ -std=c++17 -Wall --pedantic-errors TriangleTest.cpp -o triangle
int main(){
    //test 'hello.h'
    std::cout << "Test Hello()" << std::endl;
    brahman::Hello();
    std::cout << std::endl;

    //test 'area.h'
    brahman::Triangle<double> tri(2.5, 4.2, 5.0);

    std::cout << "Input data: " << tri.GetAB() << " " << tri.GetBC() << " " << tri.GetCA() << std::endl << std::endl;

    std::cout << "Test GetAB(), GetBC(), GetCA()" << std::endl;
    std::cout << "AB: " << tri.GetAB() << std::endl;
    std::cout << "BC: " << tri.GetBC() << std::endl;
    std::cout << "CA: " << tri.GetCA() << std::endl << std::endl;

    std::cout << "Test CheckShape()" << std::endl;
    std::cout << "Shape is " << tri.GetShape() << std::endl << std::endl;

    std::cout << "Test GetArea()" << std::endl;
    std::cout << "Area is " << tri.GetArea() << std::endl << std::endl;    

    std::cout << "Test PrintShape()" << std::endl;
    tri.PrintShape();
    std::cout << std::endl;

    std::cout << "Test PrintCondition()" << std::endl;
    tri.PrintCondition();
}