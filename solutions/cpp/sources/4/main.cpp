/**
 * Find largest palindrom.
 *
 * a: 3-digit number
 * b: 3-digit number
 * p: palindrom, p = a * b
 *
 * very simple forward iteration loop solution.
 */

#include <cassert>
#include <iostream>
#include <vector>

unsigned getMinNum(unsigned digitsNum)
{
    unsigned minNum = 1;
    for(unsigned i = 1; i < digitsNum; i++)
    {
        minNum *= 10;
    }
    return minNum;
}

unsigned getMaxNum(unsigned digitsNum)
{
    unsigned maxNum = 9;
    for(unsigned i = 1; i < digitsNum; i++)
    {
        maxNum *= 10;
        maxNum += 9;
    }
    return maxNum;
}

bool isPalindrom(unsigned num)
{
    std::vector<unsigned> digits;
    while(num != 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    bool isPalindrom = true;
    std::vector<unsigned>::iterator forwardIt = digits.begin();
    std::vector<unsigned>::reverse_iterator backwardIt = digits.rbegin();
    for (unsigned i = 0; i < (digits.size() / 2 + 1) && isPalindrom;
            ++i)
    {
        if(*forwardIt != *backwardIt)
        {
            isPalindrom = false;
            break;
        }
        forwardIt++;
        backwardIt++;
    }

    return isPalindrom;
}

unsigned findLargestPalindrom(unsigned digitsNum)
{
    unsigned maxNum = getMaxNum(digitsNum);
    unsigned minNum = getMinNum(digitsNum);

    unsigned palindrom;
    for(unsigned a = minNum; a <= maxNum; a++)
    {
        for(unsigned b = minNum; b <= maxNum; b++)
        {
            unsigned next = a * b;
            if (isPalindrom(next)) {
                palindrom = next;
            }
        }
    }

    return palindrom;
}

void test()
{
    assert(getMinNum(1) == 1);
    assert(getMinNum(2) == 10);
    assert(getMinNum(3) == 100);
    assert(getMinNum(9) == 100000000);

    assert(getMaxNum(1) == 9);
    assert(getMaxNum(2) == 99);
    assert(getMaxNum(3) == 999);
    assert(getMaxNum(9) == 999999999);

    assert(isPalindrom(1) == true);
    assert(isPalindrom(11) == true);
    assert(isPalindrom(456) == false);
    assert(isPalindrom(99099) == true);
    assert(isPalindrom(99999) == true);
    assert(isPalindrom(999991) == false);
    assert(isPalindrom(1233214) == false);
}

int main(int argc, char *argv[])
{
    test();

    unsigned palindrom = findLargestPalindrom(3);
    std::cout << "Largest palindrom: " << palindrom << std::endl;

    return 0;
}

