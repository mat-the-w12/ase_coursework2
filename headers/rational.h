#ifndef RATIONAL_H_161217
#define RATIONAL_H_161217

#include <string>
#include <iostream>

namespace ExactArithmetic
{
  /*
   * The Rational class represents rational numbers.
   * Unlike floats and doubles, arithmetic operations on Rational objects introduce
   * no rounding errors.
   * Example string representations of Rationals include "2/3", "-7/8", "20/9" and "6".
   */
  class Rational
  {
    public:

      // Default constructor, initialises to 0.
      Rational();

      //  Construct a Rational from a numerator and denominator.
      Rational(long long int numerator, long long int denominator);

      // Converting constructors
      Rational(int);
      Rational(double);

      /*  Accepts either a pair of integers separated by '/', or a single integer
       *  followed by a character other than '/'.
       *  For any other input, throws a std::invalid_argument exception.
       */
      explicit Rational(const std::string &);

      //  Arithmetic Operators
      Rational operator+(const Rational &) const;
      Rational operator-(const Rational &) const;
      Rational operator*(const Rational &) const;
      Rational operator/(const Rational &) const; // Division by zero throws a DivideByZeroError

      // Comparison operators
      bool operator<(const Rational &) const;
      bool operator>(const Rational &) const;
      bool operator<=(const Rational &) const;
      bool operator>=(const Rational &) const;
      bool operator==(const Rational &) const;
      bool operator!=(const Rational &) const;

      // Compound Assignment operators
      Rational & operator+=(const Rational &);
      Rational & operator-=(const Rational &);
      Rational & operator*=(const Rational &);
      Rational & operator/=(const Rational &); // Division by zero throws a DivideByZeroError

      // Negation
      static Rational abs(const Rational & r);
      static Rational negate(const Rational & r);

      // Friend declarations
      friend std::ostream & operator<<(std::ostream &, const Rational &);
      friend std::istream & operator>>(std::istream &, Rational &);

    private:
      /* A rational number can be represented as a ratio between two integers:
         called the numerator and denominator.
       */
      long long int num;   // numerator
      long long int denom; // denominator

      /* Class invariant:
       * The fraction is stored in a normal form:
       *   - the numerator and denominator are reduced to their lowest terms;
       *   - the denominator is never negative; negative rational numbers
       *     are represented using a negative numerator.
       */

      /* Normalise a fraction by reducing it to its lowest (simplest) terms.
       * This function is used internally to restore the class invariant after any
       * operation that could invalidate it.
       */
      void normalise();
  };

  /*  Prints the numerator and denominator separated by '/'.
   *  If the denominator is 1, then the '/' and denominator are omitted.
   */
  std::ostream & operator<<(std::ostream &, const Rational &);

  /*  Accepts either a pair of integers separated by '/', or a single integer
   *  followed by a character other than '/'.
   *  For any other input, the result is zero.
   */
  std::istream & operator>>(std::istream &, Rational &);
}

#endif
