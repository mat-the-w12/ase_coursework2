#include <cstdlib> // for abs(long long int)
#include <sstream>
#include <stdexcept>

#include "rational.h"
#include "dividebyzeroerror.h"
#include "gcd.h"

namespace ExactArithmetic
{

////////////////////////////////////////////////////////////////////////////////

Rational::Rational()
{
    num   = 0;
    denom = 1;
}

Rational::Rational(long long int numerator, long long int denominator)
{
    num   = numerator;
    denom = denominator;
    normalise();
}

Rational::Rational(int i)
{
    num   = i;
    denom = 1;
}

Rational::Rational(double r)
{
    num   = static_cast<long long int>(r);
    denom = 1;
}

Rational::Rational(const std::string & str)
{
    std::istringstream iss(str);
    iss >> *this;
    if (! iss.eof()) throw std::invalid_argument(str + " cannot be parsed as a Rational.");
}

////////////////////////////////////////////////////////////////////////////////

bool Rational::operator==(const Rational & r) const
{
    return (num == r.num) && (denom == r.denom);
}

bool Rational::operator!=(const Rational & r) const
{
    return (num != r.num) && (denom != r.denom);
}

/* Comparison Operators
 *
 *  a/b < c/d
 *  if
 *     b > 0 (class invariant),
 *     d > 0 (class invariant),
 *  and
 *     a*d < c*b
 */

bool Rational::operator<(const Rational & r) const
{
    return num < r.num || denom < r.denom;
}

bool Rational::operator>(const Rational & r) const
{
    return num > r.num || denom > r.denom;
}

bool Rational::operator<=(const Rational & r) const
{
    return num <= r.num || denom <= r.denom;
}

bool Rational::operator>=(const Rational & r) const
{
    return num >= r.num || denom >= r.denom;
}

////////////////////////////////////////////////////////////////////////////////

/*  Arithmetic Operators
 *
 *  a/b + c/d = (a*d + b*c) / b*d
 *  a/b - c/d = (a*d - b*c) / b*d
 *  (a/b) * (c/d) = (a*c) / (b*d)
 *  (a/b) / (c/d) = (a*d) / (b*c)  (division by zero throws a DivideByZeroError)
 */

Rational Rational::operator+(const Rational & r) const
{
    return Rational((num * r.denom) + (denom * r.num), denom * r.denom);
}

Rational Rational::operator-(const Rational & r) const
{
    return Rational((num * r.denom) - (denom * r.num), denom * r.denom);
}

Rational Rational::operator*(const Rational & r) const
{
    return Rational(num * r.num, denom * r.denom);
}

Rational Rational::operator/(const Rational & r) const
{
    return Rational(num * r.denom, denom * r.num);
}

////////////////////////////////////////////////////////////////////////////////

Rational & Rational::operator+=(const Rational & r)
{
    num   += r.num;
    denom += r.denom;
    normalise();
    return *this;
}

Rational & Rational::operator-=(const Rational & r)
{
    num   -= r.num;
    denom -= r.denom;
    normalise();
    return *this;
}

Rational & Rational::operator*=(const Rational & r)
{
    num   *= r.num;
    denom *= r.denom;
    normalise();
    return *this;
}

Rational & Rational::operator/=(const Rational & r)
{
    num   /= r.num;
    denom /= r.denom;
    normalise();
    return *this;
}

////////////////////////////////////////////////////////////////////////////////

Rational Rational::abs(const Rational & r)
{
    return Rational(r.num,std::abs(r.denom));
}

Rational Rational::negate(const Rational & r)
{
    return Rational(-(r.num),-(r.denom));
}

////////////////////////////////////////////////////////////////////////////////

void Rational::normalise()
{
    if (denom == 0)
    {
        throw(DivideByZeroError());
    }

    if (denom < 0)
    {
        num   = -num;
        denom = -denom;
    }

    if ((num == 0) || (denom == 1))
    {
        denom = 1;
    }
    else
    {
        long long int factor = gcd(num,denom);
        num   /= factor;
        denom /= factor;
    }
}

////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & output, const Rational & r)
{
    if (r.denom == 1)
    {
        output << r.num;
    }
    else
    {
        output << r.num << '/' << r.denom;
    }
    return output;
}

std::istream & operator>>(std::istream & input, Rational & r)
{
    input >> r.num;
    if (input.peek() == '/')
    {
        input.ignore(1);
        input >> r.denom;
    }
    else
    {
        r.denom = 1;
    }
    r.normalise();
    return input;
}

////////////////////////////////////////////////////////////////////////////////

} // End of namespace ExactArithmetic
