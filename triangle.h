#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>
#include<string>
#include<string_view>

namespace brahman {

template < typename T >
constexpr T sqrt( T s )
{
    T x = s / 2.0 ;
    T prev = 0.0 ;

    while ( x != prev )
    {
        prev = x ;
        x = (x + s / x ) / 2.0 ;
    }
    return x ;
}

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
    T area;
    TriangleShape shape = TriangleShape::UnInitialized;

    static constexpr T CalculateArea(T a, T b, T c)
    {
        T s = (a+b+c) / 2;
        return static_cast<T>(brahman::sqrt(s*(s-a)*(s-b)*(s-c)));
    }

public:

    constexpr explicit Triangle(T ab, T bc, T ca): ab(ab), bc(bc), ca(ca), area(Triangle::CalculateArea(ab, bc, ca)), shape(InitializeShape()) {}

    ~Triangle() = default;

    constexpr TriangleShape InitializeShape() const
    {
        if((ab + bc > ca && ab + ca > bc && bc + ca > ab) && (ab > 0 && bc > 0 && ca > 0))
        {
            if(ab == bc && bc == ca)
            {
                return TriangleShape::Equilateral;
            }
            else if(ab*ab + bc*bc == ca*ca || ab*ab + ca*ca == bc*bc || bc*bc + ca*ca == ab*ab)
            {
                if(ab == bc || bc == ca || ca == ab)
                {
                    return TriangleShape::IsoscelesRight;
                }
                else
                {
                    return TriangleShape::Right;
                }
            }
            else if(ab == bc || bc == ca || ca == ab)
            {
                return TriangleShape::Isosceles;
            }
            else
            {
                return TriangleShape::InEquilateral;
            }

        }
        else
        {
            return TriangleShape::NotTriangle;
        }
    }

    constexpr T GetAB() const
    {
        return ab;
    }
    constexpr T GetBC() const
    {
        return bc;
    }
    constexpr T GetCA() const
    {
        return ca;
    }
    constexpr T GetArea() const
    {
        return area;
    }

    constexpr std::string_view GetShape() const
    {
        using namespace std::string_view_literals;
        switch (shape)
        {
        case TriangleShape::NotTriangle:
            return "NotTriangle"sv;

        case TriangleShape::Equilateral:
            return "Equilateral Triangle"sv;

        case TriangleShape::IsoscelesRight:
            return "IsoscelesRight Triangle"sv;

        case TriangleShape::Isosceles:
            return "Isosceles Triangle"sv;

        case TriangleShape::Right:
            return "Right Triangle"sv;

        case TriangleShape::InEquilateral:
            return "InEquilateral Triangle"sv;

        default:
            return "Error"sv;//It will become exception handling
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Triangle const& tri)
    {
        os << "AB: " << tri.GetAB() << '\n';
        os << "BC: " << tri.GetBC() << '\n';
        os << "CA: " << tri.GetCA() << '\n';
        os << "Area is " << tri.GetArea() << '\n';
        os << "Shape is " << tri.GetShape() << '\n';
        return os;
    }
};
}

#endif //FIRSTLIB_PCC_AREA_H_
