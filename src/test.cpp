#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ExactArithmeticTest

#include <sstream>
#include <boost\test\included\unit_test.hpp>
#include "..\headers\rational.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE(ExactArithmetic)

BOOST_AUTO_TEST_CASE(default_constructor)
{
	Rational x;
	BOOST_CHECK_EQUAL(x, Rational(0, 1));
}

BOOST_AUTO_TEST_CASE(normalise)
{
	Rational x = Rational(2, 4);
	BOOST_CHECK_EQUAL(x, Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(single_int_input_constructor)
{
	Rational x = Rational(3);
	BOOST_CHECK_EQUAL(x, Rational(3, 1));
}

BOOST_AUTO_TEST_CASE(single_double_input_constructor)
{
	Rational x = Rational(3.2);
	BOOST_CHECK_EQUAL(x, Rational(3, 1));
}

BOOST_AUTO_TEST_CASE(string_constructor)
{
	Rational x = Rational("1/2");
	BOOST_CHECK_EQUAL(x, Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(string_constructor_error)
{
	BOOST_CHECK_THROW(Rational("adgsajzryk"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(equals_success)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) == Rational(1, 3), true);
}

BOOST_AUTO_TEST_CASE(equals_fail)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) == Rational(5, 7), false);
}

BOOST_AUTO_TEST_CASE(not_equals_success)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) != Rational(4, 9), true);
}

BOOST_AUTO_TEST_CASE(not_equals_fail)
{
	BOOST_CHECK_EQUAL(Rational(1, 3) != Rational(1, 3), false);
}

BOOST_AUTO_TEST_CASE(add)
{
	Rational x = Rational(3, 5);
	Rational y = Rational(1, 5);
	BOOST_CHECK_EQUAL(x + y, Rational(4, 5));
}

BOOST_AUTO_TEST_CASE(minus)
{
	Rational x = Rational(3, 5);
	Rational y = Rational(1, 5);
	BOOST_CHECK_EQUAL(x - y, Rational(2, 5));
}

BOOST_AUTO_TEST_CASE(multiply)
{
	Rational x = Rational(3, 5);
	Rational y = Rational(2, 7);
	BOOST_CHECK_EQUAL(x * y, Rational(6, 35));
}

BOOST_AUTO_TEST_CASE(divide)
{
	Rational x = Rational(5, 8);
	Rational y = Rational(3, 4);
	BOOST_CHECK_EQUAL(x / y, Rational(5, 6));
}

BOOST_AUTO_TEST_CASE(more_than_I)
{
	Rational x = Rational(1, 3);
	Rational y = Rational(2, 3);
	BOOST_CHECK_EQUAL(x > y, false);
}

BOOST_AUTO_TEST_CASE(more_than_II)
{
	Rational x = Rational(1, 3);
	Rational y = Rational(1, 2);
	BOOST_CHECK_EQUAL(x > y, false);
}

BOOST_AUTO_TEST_CASE(less_than)
{
	Rational x = Rational(1, 3);
	Rational y = Rational(2, 3);
	BOOST_CHECK_EQUAL(x < y, true);
}

BOOST_AUTO_TEST_CASE(output)
{
	Rational x = Rational(1, 2);
	std::ostringstream testOutputStream;
	testOutputStream << x;
	BOOST_CHECK_EQUAL(testOutputStream.str(), "1/2");
}

BOOST_AUTO_TEST_CASE(input)
{
	Rational x;
	std::istringstream testInputStream("1/2");
	testInputStream >> x;
	BOOST_CHECK_EQUAL(x, Rational(1, 2));
}

BOOST_AUTO_TEST_SUITE_END()