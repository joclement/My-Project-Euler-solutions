#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

/**
 * Smallest number dividable by 1 - 20.
 *
 * 1 - 20 -> 11 - 20
 */

std::vector<unsigned> getRelevantDivisorsSorted(unsigned upperRange)
{
    std::vector<unsigned> relevants;

    for (unsigned num = upperRange / 2 + 1; num <= upperRange; ++num) {
        relevants.push_back(num);
    }

    std::sort(relevants.begin(), relevants.end());

    return relevants;
}

bool isDividable(unsigned divident, std::vector<unsigned> divisors)
{
    for (std::vector<unsigned>::iterator divisor = divisors.begin();
            divisor < divisors.end(); ++divisor) {
        if(divident % *divisor != 0)
        {
            return false;
        }
    }

    return true;
}

unsigned simpleFind(std::vector<unsigned> divisors)
{
    unsigned number = 0;
    unsigned increment = divisors[divisors.size() - 1];
    while(true)
    {
        number += increment;
        if(isDividable(number, divisors))
        {
            return number;
        }
    }
}

void test()
{
}

int main(int argc, char *argv[])
{
    test();

    std::cout << "Smallest number: "
              << simpleFind(getRelevantDivisorsSorted(20))
              << std::endl;
    return 0;
}
