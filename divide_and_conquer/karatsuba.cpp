#include <algorithm>
#include <string>

#include "big_number_ops.hpp"

/*
 * (a + b)*(c + d) = a*c + a*d + b*c + b*d
 * a*d + b*c = (a + b)*(c + d) - (a*c + b*d)
 *
 * given n (10^m <= n < 10^(m+1))
 * n1 = 10^(m/2)*a + b
 * n2 = 10^(m/2)*c + d
 * n1 * n2 = 10^m*a*c + 10^(m/2)(a*d + b*c) + bd
 *         = 10^m*a*c + 10^(m/2)((a + d)*(c + d) - (a*c + b*d)) + bd
 */
void
karatsuba_internal(
  std::string::iterator start,
  std::string::iterator end,
  std::string_view left,
  std::string_view right
);

/*
 * assume lowest byte for lowest digit and highest byte for highest digit
 * and each byte contains integer but ascii value. 0 instead of '0'.
 */
std::string karatsuba(std::string& left, std::string& right)
{
  std::string result(left.size() + right.size(), 0);

  karatsuba_internal(result.begin(), result.end(), left, right);
  return result;
}

void
karatsuba_internal(
  std::string::iterator start,
  std::string::iterator end,
  std::string_view left,
  std::string_view right
) {
  if (left.size() < right.size())
  {
    left.swap(right);
  }
  if (left.size() == 1)
  {
    unsigned int num = left[0] * right[0];
    *start += num % 10;
    *(start + 1) += num / 10;
  }
  size_t  m = left.size();
  std::string_view  a = left.substr(m/2, m);
  std::string_view  b = left.substr(0, m/2);
  std::string_view  c;
  std::string_view  d = right.substr(0, m/2);
  if (right.size() > m/2)
  {
    c = right.substr(m/2, m);
  }
}
