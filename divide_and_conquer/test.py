import random
import array
import sys


def generateRandomByDigits(n: int):
    lowerBound = 10 ** (n - 1)
    upperBound = 10 ** n - 1
    return random.randint(lowerBound, upperBound)


ops = {'-', '*'}

rangeArr = array.array('I')
rangeArr.append(1)
for i in range(15):
    rangeArr.append(rangeArr[i] * 2)

addr, len = rangeArr.buffer_info()
maxDigits = 2 ** len

if (maxDigits > 640):
    sys.set_int_max_str_digits(maxDigits * 2 + 1)

with open("test_cases.txt", "w") as f:
    for op in ops:
        f.write(f'begin\n{op}\n')
        count = 0
        for i in rangeArr:
            a: int = generateRandomByDigits(i)
            b: int = generateRandomByDigits(i)
            c: int
            if op == '-':
                c = a - b
            elif op == '*':
                c = a * b
            f.write(f'{str(a)}\n{str(b)}\n{str(c)}\n')
            count += 1
        f.write('end\n')
