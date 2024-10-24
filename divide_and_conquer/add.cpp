#include <string>
#include <tuple>
#include <vector>
#include <iostream>

std::string add(std::string str1, std::string str2)
{
  std::string ret;

  if (str1.size() < str2.size())
    str1.swap(str2);

  ret.reserve(str1.size() + 1);

  std::string::reverse_iterator i1, i2;
  int carry = 0;

  i1 = str1.rbegin();
  i2 = str2.rbegin();
  while (i2 != str2.rend()) {
    int num = *i1++ + *i2++ - 2 * '0' + carry;

    carry = num > 9;
    ret.push_back(num % 10 + '0');
  }
  while (i1 != str1.rend()) {
    int num = *i1++ - '0' + carry;

    carry = num > 9;
    ret.push_back(num % 10 + '0');
  }
  if (carry == 1)
    ret.push_back('1');
  auto left = ret.begin(), right = ret.end() - 1;
  while (left < right) {
    std::swap(*left, *right);
    ++left;
    --right;
  }
  return ret;
}

int main()
{
  std::vector<std::tuple<std::string, std::string, std::string>> tests = {
    std::make_tuple("12", "34", std::to_string(12 + 34)),
    std::make_tuple("1", "34", std::to_string(1 + 34)),
    std::make_tuple("1192382", "20387923", std::to_string(1192382 + 20387923)),
    std::make_tuple("20387923", "1192382", std::to_string(1192382 + 20387923)),
    std::make_tuple("99999", "99999", std::to_string(99999 + 99999)),
    std::make_tuple("1", "99999", std::to_string(100000)),
    std::make_tuple("0", "0", std::to_string(0)),
    std::make_tuple("0", "42", std::to_string(42)),
    std::make_tuple("42", "0", std::to_string(42)),
    std::make_tuple("12312415346245634", "2346457345634563456", "2358769760980809090"),
  };

  int i = 0;
  for (auto& test: tests) {
    std::string result = add(std::get<0>(test), std::get<1>(test));

    if (result != std::get<2>(test)) {
      std::cout << "case " << i << ": false\n";
      std::cout << "yours=" << result << '\n';
      std::cout << "answer=" << std::get<2>(test) << '\n';
    } else {
      std::cout << "case " << i << ": OK\n";
    }
    ++i;
  }
}
