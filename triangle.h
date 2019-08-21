#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>
#include<string>

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

    void CalculateArea()
    {
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
    T GetArea() const
    {
        return area;
    }

    std::string GetShape() const
    {
        
        switch (shape)
        {

        case TriangleShape::NotTriangle:
            return std::string("NotTriangle");
            break;

        case TriangleShape::Equilateral:
            return std::string("Equilateral Triangle");
            break;
        
        case TriangleShape::IsoscelesRight:
            return std::string("IsoscelesRight Triangle");
            break;

        case TriangleShape::Isosceles:
            return std::string("Isosceles Triangle");
            break;

        case TriangleShape::Right:
            return std::string("Right Triangle");
            break;

        case TriangleShape::InEquilateral:
            return std::string("InEquilateral Triangle");
            break;

        default:
            return std::string("Error");//It will become exception handling
            break;
        }
    }    

    void PrintCondition()
    {
        std::cout << "AB: " << GetAB() << std::endl;
        std::cout << "BC: " << GetBC() << std::endl;
        std::cout << "CA: " << GetCA() << std::endl;
        std::cout << "Area is " << GetArea() << std::endl;        
        std::cout << "Shape is " << GetShape() << std::endl;
    }
};
}

#endif //FIRSTLIB_PCC_AREA_H_