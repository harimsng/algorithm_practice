import random
import sys


def generateRandomByDigits(n: int):
    lowerBound = 10 ** n
    upperBound = 10 ** (n + 1)
    return random.randint(lowerBound, upperBound)


startDigits = 1
step = 10
maxDigits = 500
ops = {'-', '*'}

if (maxDigits > 640):
    sys.set_int_max_str_digits(maxDigits * 2 + 1)

with open("test_cases.txt", "w") as f:
    for op in ops:
        f.write(f'begin\n{op}\n')
        count = 0
        for i in range(startDigits, maxDigits, step):
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
