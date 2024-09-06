#include <algorithm>
#include <string>

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
std::string karatsuba(std::string& left, std::string& right)
{
  size_t    nDigits = std::max(left.size(), right.size());
  std::string result(left.size() + right.size(), 0);

  if (nDigits == 1)
  {
    unsigned int  
    result
  }
}
