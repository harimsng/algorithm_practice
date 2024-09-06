#ifndef _BIGNUMBEROPS_HPP_
# define _BIGNUMBEROPS_HPP_

#include "subtraction_template.hpp"
#include "multiplication_template.hpp"

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
    return subtract<Container, ConvertFromInt, ConvertToInt>(l, r);
  }
  Container mul(Container& l, Container& r)
  {
    return multiply<Container, ConvertFromInt, ConvertToInt>(l, r);
  }
};

static inline char convertFromInt(unsigned int i)
{
  return i + '0';
}
static inline unsigned int convertToInt(char c)
{
  return c - '0';
}


#endif //_BIGNUMBEROPS_HPP_
