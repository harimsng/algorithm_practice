#ifndef _MULTIPLICATION_TEMPLATE_HPP_
# define _MULTIPLICATION_TEMPLATE_HPP_

#include <utility>

template
<
  typename container,
  typename container::value_type convertFromInt(unsigned int),
  unsigned int convertToInt(typename container::value_type)
>
container multiply (container& left, container& right)
{
  container result(left.size() + right.size(), convertFromInt(0));

  typename container::reverse_iterator lri = left.rbegin();
  typename container::reverse_iterator rri = right.rbegin();
  unsigned int carry = 0;
  unsigned int i = 0;
  unsigned int j = 0;
  while (lri != left.rend())
  {
    j = 0;
    rri = right.rbegin();
    while (rri != right.rend())
    {
      unsigned int num;

      num =
        convertToInt(*lri) * convertToInt(*rri) + convertToInt(result[i + j]) + carry;
      carry = num / 10;
      result[i + j] = convertFromInt(num % 10);
      ++j;
      ++rri;
    }
    if (carry > 0)
    {
      result[i + j] = convertFromInt(carry);
    }
    carry = 0;
    ++i;
    ++lri;
  }
  while (result.size() > 1 && convertToInt(result.back()) == 0) {
    result.pop_back();
  }

  typename container::iterator li = result.begin();
  typename container::iterator ri = --result.end();
  while (li < ri)
  {
    std::swap(*li, *ri);
    ++li;
    --ri;
  }
  return result;
}

#endif //_MULTIPLICATION_TEMPLATE_HPP_
