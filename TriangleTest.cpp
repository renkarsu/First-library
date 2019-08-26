#include"hello.h"
#include"triangle.h"

//g++ -std=c++17 -Wall --pedantic-errors TriangleTest.cpp -o triangle
int main(){
    //test 'hello.h'
    std::cout << "Test Hello()" << '\n';
    brahman::Hello();
    std::cout << '\n';

    //test 'area.h'
    constexpr brahman::Triangle<double> tri(2.5, 4.2, 5.0);

    std::cout << "Input data: " << tri.GetAB() << " " << tri.GetBC() << " " << tri.GetCA() << '\n' << '\n';

    std::cout << "Test GetAB(), GetBC(), GetCA()" << '\n';
    std::cout << "tri.GetAB(): " << tri.GetAB() << '\n';
    std::cout << "tri.GetBC(): " << tri.GetBC() << '\n';
    std::cout << "tri.GetCA(): " << tri.GetCA() << '\n' << '\n';

    std::cout << "Test GetArea()" << '\n';
    std::cout << "tri.GetArea(): " << tri.GetArea() << '\n' << '\n';

    std::cout << "Test GetShape()" << '\n';
    std::cout << "tri.GetShape(): " << tri.GetShape() << '\n' << '\n';

    std::cout << "Test operator <<" << '\n';
    std::cout << tri;
}