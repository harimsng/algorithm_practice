#ifndef _SUBTRACTION_TEMPLATE_HPP_
# define _SUBTRACTION_TEMPLATE_HPP_

#include <utility>

template
<
  typename container,
  typename container::value_type convertFromInt(unsigned int),
  unsigned int convertToInt(typename container::value_type)
>
container subtract (container& left, container& right)
{
  container result;
  bool negative = false;

  if (left.size() == right.size()) {
    int comp = left.compare(right);
    if (comp == 0)
      return "0";
    else if (comp < 0) {
      negative = true;
      left.swap(right);
    }
  } else if (left.size() < right.size()) {
    negative = true;
    left.swap(right);
  }
  result.reserve(left.size() + 1);
  {
    typename container::reverse_iterator leftI;
    typename container::reverse_iterator rightI;
    int carry = 0;

    leftI = left.rbegin();
    rightI = right.rbegin();

    while (rightI != right.rend()) {
      int diff = *leftI - *rightI + carry;
      if (diff < 0) {
        diff = 10 + diff;
        carry = -1;
      } else {
        carry = 0;
      }
      result.push_back(convertFromInt(diff));
      ++rightI;
      ++leftI;
    }
    while (leftI != left.rend()) {
      int diff = convertToInt(*leftI) + carry;
      if (diff < 0) {
        diff = 10 + diff;
        carry = -1;
      } else {
        carry = 0;
      }
      result.push_back(convertFromInt(diff));
      ++leftI;
    }
  }

  typename container::iterator leftI = result.begin();
  typename container::iterator rightI = --result.end();

  while (*rightI == '0') {
    result.erase(rightI);
    --rightI;
  }
  if (negative == true) {
    rightI = result.insert(result.end(), '-');
  }
  while (leftI < rightI) {
    std::swap(*leftI, *rightI);
    ++leftI;
    --rightI;
  }
  return result;
}

#endif //_SUBTRACTION_TEMPLATE_HPP_
