#include <string>
#include <utility>

std::string subtract(std::string& left, std::string& right)
{
  std::string result;
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
    typename std::string::reverse_iterator leftI;
    typename std::string::reverse_iterator rightI;
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
      result.push_back(diff + '0');
      ++rightI;
      ++leftI;
    }
    while (leftI != left.rend()) {
      int diff = *leftI + carry;
      if (diff < '0') {
        diff = 10 + diff;
        carry = -1;
      } else {
        carry = 0;
      }
      result.push_back(diff);
      ++leftI;
    }
  }

  typename std::string::iterator leftI = result.begin();
  typename std::string::iterator rightI = --result.end();

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
