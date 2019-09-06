#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>
#include<string>
#include<string_view>

namespace brahman {
//SUGGESTION: make math header, then put this function.
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
    const T ab;
    const T bc;
    const T ca;
    const T area;
    const TriangleShape shape;

//TODO: intでクラスをインスタンス化すると面積の誤差が酷い
    static constexpr T CalculateArea(T a, T b, T c) noexcept
    {
        T s =  static_cast<T>(a+b+c) / 2;
        return static_cast<T>(brahman::sqrt(s*(s-a)*(s-b)*(s-c)));
    }

    static constexpr bool IsTriangle(T a, T b, T c) noexcept
    {
        if( (a+b>c && b+c>a && c+a>b) && (a>0 && b>0 && c>0) ) return true;
        else                                                   return false;
    }
    static constexpr bool IsEquilateral(T a, T b, T c) noexcept
    {
        if(a==b && b==c) return true;
        else             return false;
    }
    static constexpr bool IsRight(T a, T b, T c) noexcept
    {
        if(a*a+b*b == c*c||b*b+c*c == a*a||c*c+a*a == b*b) return true;
        else                                               return false;
    }
    static constexpr bool IsIsosceles(T a, T b, T c) noexcept
    {
        if(a==b||b==c||c==a) return true;
        else                 return false;
    }

    static constexpr TriangleShape InitializeShape(T a, T b, T c) noexcept
    {
        if(!IsTriangle(a, b, c))
                return TriangleShape::NotTriangle;

        if(IsEquilateral(a, b, c))
                return TriangleShape::Equilateral;

        else if(IsRight(a, b, c))
        {
            if(IsIsosceles(a, b, c))
                return TriangleShape::IsoscelesRight;
            else
                return TriangleShape::Right;
        }

        else if(IsIsosceles(a, b, c))
                return TriangleShape::Isosceles;

        else
                return TriangleShape::InEquilateral;
    }

public:

    constexpr explicit Triangle(T ab, T bc, T ca): ab(ab), bc(bc), ca(ca), area(Triangle::CalculateArea(ab, bc, ca)), shape(Triangle::InitializeShape(ab, bc, ca)) {}

    ~Triangle() = default;

    constexpr T GetAB() const noexcept
    {
        return ab;
    }
    constexpr T GetBC() const noexcept
    {
        return bc;
    }
    constexpr T GetCA() const noexcept
    {
        return ca;
    }
    constexpr T GetArea() const noexcept
    {
        return area;
    }

    constexpr std::string_view GetShape() const noexcept
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
            return "Error"sv;
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
