#include <cassert>
#include <iostream>

/**
 * Difference between square of sum and sum of squares of first 100 natural
 * numbers.
 */

unsigned calcSquareOfSum(unsigned range)
{
    unsigned sum = range * (range + 1) / 2;

    return sum * sum;
}

unsigned calcSumOfSquares(unsigned range)
{
    unsigned sum = 0;
    for (unsigned i = 1; i <= range; ++i) {
        sum += i * i;
    }

    return sum;
}

unsigned difference(unsigned range)
{
    unsigned squareOfSum = calcSquareOfSum(range);
    unsigned sumOfSquares = calcSumOfSquares(range);

    if(squareOfSum > sumOfSquares)
    {
        return squareOfSum - sumOfSquares;
    }
    return sumOfSquares - squareOfSum;
}

void test()
{
    assert(difference(10) == 2640);
}

int main(int argc, char *argv[])
{
    test();

    std::cout << "Diff: " << difference(100) << std::endl;

    return 0;
}
