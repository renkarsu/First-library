#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>

namespace brahman{

enum TriangleShape
{
    NotTriangle,
    Equilateral,
    IsoscelesRight,
    Isosceles,
    Right,
    InEquilateral,
    UnInitialized = -1,
};


template <typename T>
class Triangle
{
    T ab;//Didn't use const, because I'm going to implement side-length extension function.
    T bc;
    T ca;
    TriangleShape shape;
    T area;

public:

    Triangle(T ab, T bc, T ca): ab(ab), bc(bc), ca(ca), shape(UnInitialized)
    {
        CheckShape();
        CalculateArea();
    }

    ~Triangle()
    {

    }

    void CheckShape()
    {
        if((ab + bc > ca && ab + ca > bc && bc + ca > ab) && (ab > 0 && bc > 0 && ca > 0))
        {
            if(ab == bc && bc == ca)
            {
                shape = Equilateral;
            }
            else if(ab*ab + bc*bc == ca*ca || ab*ab + ca*ca == bc*bc || bc*bc + ca*ca == ab*ab)
            {
                if(ab == bc || bc == ca || ca == ab)
                {
                    shape = IsoscelesRight;
                }
                else
                {
                    shape = Right;
                }
            }
            else if(ab == bc || bc == ca || ca == ab)
            {
                shape = Isosceles;
            }
            else
            {
                shape = InEquilateral;
            }
            
        }
        else
        {
            shape = NotTriangle;
        }
    }

    void CalculateArea(){
        T s = static_cast<T>(ab+bc+ca)/2;//Is cast necessary?
        area = sqrt(s*(s-ab)*(s-bc)*(s-ca));
    }    

    T GetAB() const
    {
        return ab;
    }
    T GetBC() const
    {
        return bc;
    }
    T GetCA() const
    {
        return ca;
    }
    T GetShape()
    {
        return shape;
    }
    T GetArea(){
        return area;
    }

    void PrintShape(){
        
        switch (shape)
        {

        case 0:
            std::cout << "Not a Triangle" << std::endl;
            break;

        case 1:
            std::cout << "Equilateral Triangle" << std::endl;
            break;
        
        case 2:
            std::cout << "IsoscelesRight Triangle" << std::endl;
            break;

        case 3:
            std::cout << "Isosceles Triangle" << std::endl;
            break;

        case 4:
            std::cout << "Right Triangle" << std::endl;
            break;

        case 5:
            std::cout << "InEquilateral Triangle" << std::endl;
            break;

        default:
            std::cout << "Error" << std::endl;//It will become exception handling
            break;
        }
    }    

    void PrintCondition()
    {
        std::cout << GetAB() << std::endl;
        std::cout << GetBC() << std::endl;
        std::cout << GetCA() << std::endl;
        PrintShape();
        std::cout << GetArea() << std::endl;
    }
};
}

#endif //FIRSTLIB_PCC_AREA_H_