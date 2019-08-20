#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>

namespace brahman{

enum class TriangleShape
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

    Triangle(T ab, T bc, T ca): ab(ab), bc(bc), ca(ca), shape(TriangleShape::UnInitialized)
    {
        InitializeShape();
        CalculateArea();
    }

    ~Triangle()
    {

    }

    void InitializeShape()
    {
        if((ab + bc > ca && ab + ca > bc && bc + ca > ab) && (ab > 0 && bc > 0 && ca > 0))
        {
            if(ab == bc && bc == ca)
            {
                shape = TriangleShape::Equilateral;
            }
            else if(ab*ab + bc*bc == ca*ca || ab*ab + ca*ca == bc*bc || bc*bc + ca*ca == ab*ab)
            {
                if(ab == bc || bc == ca || ca == ab)
                {
                    shape = TriangleShape::IsoscelesRight;
                }
                else
                {
                    shape = TriangleShape::Right;
                }
            }
            else if(ab == bc || bc == ca || ca == ab)
            {
                shape = TriangleShape::Isosceles;
            }
            else
            {
                shape = TriangleShape::InEquilateral;
            }
            
        }
        else
        {
            shape = TriangleShape::NotTriangle;
        }
    }

    void CalculateArea(){
        T s = static_cast<T>(ab+bc+ca)/2;//Is cast necessary? Yes, necessary
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
    T GetShape() const
    {
        return static_cast<T>(shape);
    }
    T GetArea() const
    {
        return area;
    }

    void PrintShape(){
        
        switch (shape)
        {

        case TriangleShape::NotTriangle:
            std::cout << "Not a Triangle" << std::endl;
            break;

        case TriangleShape::Equilateral:
            std::cout << "Equilateral Triangle" << std::endl;
            break;
        
        case TriangleShape::IsoscelesRight:
            std::cout << "IsoscelesRight Triangle" << std::endl;
            break;

        case TriangleShape::Isosceles:
            std::cout << "Isosceles Triangle" << std::endl;
            break;

        case TriangleShape::Right:
            std::cout << "Right Triangle" << std::endl;
            break;

        case TriangleShape::InEquilateral:
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