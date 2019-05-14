#include <cstdlib> // for abs(long long int)
#include <algorithm> // for min()

#include "..\headers\gcd.h"

namespace ExactArithmetic
{

long long int gcd(long long int i, long long int j)
/*
 *  Note:
 *  This is a very inefficent algorithm for computing the greatest common divisor.
 *  Euclid's Algorithm would be much more efficient.
 */
{
    long long int potentialFactor = std::min(std::abs(i), std::abs(j));
    if (potentialFactor == 0) return 1; // To avoid returning 0 when one argument is 0.

    for (; potentialFactor > 1; --potentialFactor)
    {
        if (i % potentialFactor == 0 && j % potentialFactor == 0) break; // Found a common divisor.
    }

    return potentialFactor;
}

} // End of namespace ExactArithmetic
