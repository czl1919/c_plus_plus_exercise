#ifndef __COMPLEX__
#define __COMPLEX__
#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(double r=0, double i=0)
    :re(r) im(i)
    {}

    Complex& operator += (const Complex& c);

    double real() const { return re; }

    double imag() const { return im; }
private:
    double re, im;
    friend Complex& __doapl(Complex&, const Complex&);
};
inline Complex& __doapl(Complex& ths, const Complex& r) {
    ths.re += r.re;
    ths.im += r.im;

    return ths;
}
inline Complex& Complex::operator += (const Complex& r)
{
    return __doapl(this, r);
}
inline Complex operator + (const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(),
    l.imag(), r.imag());
}
inline Complex operator + (const Complex& l, double n)
{
    return Complex(l.real() +n,
    l.imag());
}
inline Complex operator + (double n, const Complex& r)
{
    return Complex(r.real() + n,
    r.imag());
}
inline ostream& opeartor << (ostream& os, const Complex& c)
{
    return os << "(" << c.real() << ", " << c.imag() << ")";
}

#endif