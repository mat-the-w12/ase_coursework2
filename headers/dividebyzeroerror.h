#ifndef DIVIDEBYZEROERROR_H_161217
#define DIVIDEBYZEROERROR_H_161217

#include <stdexcept>

namespace ExactArithmetic
{
  class DivideByZeroError : public std::domain_error
  {
    public:
      DivideByZeroError() : std::domain_error("Divide by zero") {}
  };
}

#endif
