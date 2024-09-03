#ifndef _MULTIPLICATION_HPP_
# define _MULTIPLICATION_HPP_

#include <utility>

template <typename container>
container
multiply
(
  container& left,
  container& right,
  typename container::value_type convertFromInt(unsigned int),
  unsigned int convertToInt(typename container::value_type)
) {
  container result(left.size() + right.size(), convertFromInt(0));
  unsigned int carry = 0;
  {
    typename container::reverse_iterator li = left.rbegin();
    typename container::reverse_iterator ri = right.rbegin();
    unsigned int i = 0;
    unsigned int j = 0;
    while (li != left.rend())
    {
      j = 0;
      while (ri != right.rend())
      {
        unsigned int num;

        num = convertToInt(*li) * convertToInt(*ri) + convertToInt(result[i + j]) + carry;
        carry = num / 10;
        result[i + j] = convertFromInt(num % 10);
        ++j;
      }
      ++i;
    }
    if (carry > 0)
    {
      result[i + j] = convertFromInt(carry);
      ++i;
    }
    result.erase(result.begin() + i + j, result.end());
  }

  typename container::iterator li = result.begin();
  typename container::iterator ri = result.end();
  while (li < ri)
  {
    std::swap(*li, *ri);
    ++li;
    --ri;
  }
  return result;
}

#endif //_MULTIPLICATION_HPP_
