#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "BigNumberOps.hpp"

static char convertFromInt(unsigned int i)
{
  return i + '0';
}
static unsigned int convertToInt(char c)
{
  return c - '0';
}

int test();

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    return test();
  }
  if (argc != 4)
  {
    std::cout << "usage: ./bignumcal  left  operator  right\n";
    std::cout << "left and right must be zero or positive integer.\n";
    std::cout << "'-' for subtraction and '*' or 'x' for multiplication are currently supported operators.\n";
    return 1;
  }
  BigNumberOps<std::string, convertFromInt, convertToInt> ops;
  std::string op(argv[2]);
  std::string result;
  std::string left(argv[1]);
  std::string right(argv[3]);

  if (op.size() > 1)
  {
    std::cout << "invalid operator " << op << "\n";
    return 1;
  }
  switch (op[0])
  {
    case '+':
      std::cout << "addition is not supported\n";
      break;
    case '-':
      result = ops.sub(left, right);
      break;
    case 'x':
    case '*':
      result = ops.mul(left, right);
      break;
    case '/':
      std::cout << "division is not supported\n";
      break;
    default:
      std::cout << "invalid operator " << op[0] << "\n";
      break;
  }
  std::cout << result << '\n';
}

int test()
{
  std::fstream  fs;
  std::string   testfile("test_cases.txt");
  BigNumberOps<std::string, convertFromInt, convertToInt> ops;

  fs.open(testfile, std::ios_base::in);
  if (fs.bad() == true)
  {
    std::cerr << "failed to open " << testfile << '\n';
  }
  while (fs.good() == true)
  {
    std::string line;
    char op;

    std::getline(fs, line);
    if (fs.eof() == true)
    {
      break;
    }
    if (line.compare("begin") != 0)
    {
      std::cerr << "invalid test file: " << line << '\n';
      return 1;
    }
    std::getline(fs, line);
    std::cout << "test for '" << line << "'\n";
    op = line[0];
    while (1)
    {
      std::string a;
      std::string b;
      std::string c;
      std::string answer;

      std::getline(fs, a);
      if (a == "end") 
      {
        break;
      }
      std::getline(fs, b);
      std::getline(fs, c);
      const auto start = std::chrono::steady_clock::now();
      switch (op)
      {
        case '-':
          answer = ops.sub(a, b);
          break;
        case '*':
          answer = ops.mul(a, b);
          break;
      }
      const auto end = std::chrono::steady_clock::now();
      std::cout.setf(std::ios_base::fixed);
      std::cout
        << "N=" << a.size()
        << " M=" << b.size()
        << " interval=" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000.0 << " us\n";
      if (answer != c)
      {
        std::cout << "FAIL\n";
        if (answer.size() < 20)
        {
          std::cout << "answer: " << answer << " != " << c << '\n';
        }
        return 1;
      }
    }
    std::cout << "test for '" << op << "' success\n";
  }
  return 0;
}
