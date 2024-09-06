#include <algorithm>
#include <string>

std::string multiply_internal(std::string& left, std::string& right);

std::string multiply(std::string& left, std::string& right)
{
  std::reverse(left.begin(), left.end());
  std::reverse(right.begin(), right.end());
  std::for_each(left.begin(), left.end(),
  [](char& c)
  {
    c -= '0';
  });
  std::for_each(right.begin(), right.end(),
  [](char& c)
  {
    c -= '0';
  });
  std::string result = multiply_internal(left, right);
  std::reverse(result.begin(), result.end());
  std::for_each(result.begin(), result.end(),
  [](char& c)
  {
    c += '0';
  });
  return result;
}

std::string multiply_internal(std::string& left, std::string& right)
{
  std::string result(left.size() + right.size(), 0);

  typename std::string::iterator litr = left.begin();
  typename std::string::iterator ritr = right.begin();
  unsigned int carry = 0;
  unsigned int i = 0;
  unsigned int j = 0;
  while (litr != left.end())
  {
    j = 0;
    ritr = right.begin();
    while (ritr != right.end())
    {
      unsigned int num;

      num =
        *litr * *ritr + result[i + j] + carry;
      carry = num / 10;
      result[i + j] = (num % 10);
      ++j;
      ++ritr;
    }
    if (carry > 0)
    {
      result[i + j] = carry;
    }
    carry = 0;
    ++i;
    ++litr;
  }
  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }
  return result;
}
