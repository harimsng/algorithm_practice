#ifndef _BIGNUMBEROPS_HPP_
# define _BIGNUMBEROPS_HPP_

#include "subtraction.hpp"
#include "multiplication.hpp"

template <typename Container>
struct BigNumberOps
{
  typedef typename Container::value_type  ValueType;
  typedef ValueType (*ConvertFromInt)(unsigned int);
  typedef unsigned int (*ConvertToInt)(ValueType);
  typedef Container (*Operation)(Container&, Container&, ConvertFromInt, ConvertToInt); 
  typedef Container (*SimpleOps)(Container&, Container&);

  BigNumberOps() = delete;
  BigNumberOps(const BigNumberOps& instance) = delete;
  BigNumberOps operator=(const BigNumberOps& instance) = delete;

  BigNumberOps(ConvertFromInt f, ConvertToInt t)
  : 
    add(nullptr),
    sub([f, t](Container& l, Container& r) -> Container
    {
      return subtract<Container>(l, r, f, t);
    }),
    mul([f, t](Container& l, Container& r) -> Container
    {
      return multiply<Container>(l, r, f, t);
    }),
    div(nullptr)
  {
  }
  SimpleOps add;
  SimpleOps sub;
  SimpleOps mul;
  SimpleOps div;
};

#endif //_BIGNUMBEROPS_HPP_
