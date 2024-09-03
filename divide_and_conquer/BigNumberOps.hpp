#ifndef _BIGNUMBEROPS_HPP_
# define _BIGNUMBEROPS_HPP_

#include "subtraction.hpp"
#include "multiplication.hpp"

template
<
  typename Container,
  typename Container::value_type (*ConvertFromInt)(unsigned int),
  unsigned int (*ConvertToInt)(typename Container::value_type)
>
struct BigNumberOps
{
  BigNumberOps() = default;
  BigNumberOps(const BigNumberOps& instance) = delete;
  BigNumberOps operator=(const BigNumberOps& instance) = delete;

  Container sub(Container& l, Container& r)
  {
    return subtract(l, r, ConvertFromInt, ConvertToInt);
  }
  Container mul(Container& l, Container& r)
  {
    return multiply(l, r, ConvertFromInt, ConvertToInt);
  }
};

#endif //_BIGNUMBEROPS_HPP_
