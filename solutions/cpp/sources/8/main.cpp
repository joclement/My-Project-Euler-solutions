#include <cassert>
#include <iostream>
#include <vector>

/**
 * Compute the biggest product of n adjacent digits in the following big number.
 */

const std::string num = "73167176531330624919225119674426574742355349194934"
                        "96983520312774506326239578318016984801869478851843"
                        "85861560789112949495459501737958331952853208805511"
                        "12540698747158523863050715693290963295227443043557"
                        "66896648950445244523161731856403098711121722383113"
                        "62229893423380308135336276614282806444486645238749"
                        "30358907296290491560440772390713810515859307960866"
                        "70172427121883998797908792274921901699720888093776"
                        "65727333001053367881220235421809751254540594752243"
                        "52584907711670556013604839586446706324415722155397"
                        "53697817977846174064955149290862569321978468622482"
                        "83972241375657056057490261407972968652414535100474"
                        "82166370484403199890008895243450658541227588666881"
                        "16427171479924442928230863465674813919123162824586"
                        "17866458359124566529476545682848912883142607690042"
                        "24219022671055626321111109370544217506941658960408"
                        "07198403850962455444362981230987879927244284909188"
                        "84580156166097919133875499200524063689912560717606"
                        "05886116467109405077541002256983155200055935729725"
                        "71636269561882670428252483600823257530420752963450";

unsigned short convertCharToDigit(const char digit)
{
    unsigned short convertedDigit = digit - '0';
    assert(convertedDigit >= 0 && convertedDigit <= 9);
    return convertedDigit;
}

const std::vector<unsigned short> stringToVector(const std::string& num)
{
    std::vector<unsigned short> digits;

    for (unsigned i = 0; i < num.size(); ++i)
    {
        if (i % 100 == 0) std::cout << "Index: " << i << std::endl;
        digits.push_back(convertCharToDigit(num[i]));
    }
    return digits;
}

unsigned long calcGroupProduct(const std::vector<unsigned short> group)
{
    unsigned long product = 1;
    for (std::vector<unsigned short>::const_iterator digit = group.begin();
            digit != group.end(); ++digit)
    {
        product *= *digit;
    }
    return product;
}

unsigned long calcBiggestProductGroup(const std::string& num,
                                      const unsigned groupSize)
{
    unsigned long maxGroupProduct = 0;

    const std::vector<unsigned short> digits = stringToVector(num);
    for (std::vector<unsigned short>::const_iterator groupStart = digits.begin();
            groupStart != digits.end(); ++groupStart)
    {
        std::vector<unsigned short> newGroup;
        std::cout << "*groupStart: " << *groupStart << std::endl;
        for (std::vector<unsigned short>::const_iterator digitPtr = groupStart;
                digitPtr != digits.end() && newGroup.size() < groupSize;
                ++digitPtr)
        {
            std::cout << "*digitPtr: " << *digitPtr << std::endl;
            newGroup.push_back(*digitPtr);
        }

        if (newGroup.size() == groupSize)
        {
            unsigned long newGroupProduct = calcGroupProduct(newGroup);
            std::cout << "newGroupProduct: " << newGroupProduct << std::endl;
            if (newGroupProduct > maxGroupProduct)
            {
                maxGroupProduct = newGroupProduct;
            }
        }
        else
        {
            break;
        }
    }
    std::cout << "max: " << maxGroupProduct << std::endl;
    return maxGroupProduct;
}

void test()
{
    assert(calcBiggestProductGroup(num, 4) == 5832);
    assert(calcBiggestProductGroup(num, 1) == 9);
    assert(calcBiggestProductGroup(num, 2) == 81);
    assert(calcBiggestProductGroup(num, 3) == 9 * 9 * 8);

    std::cout << "Test was successful" << std::endl;
}

int main(int argc, char *argv[])
{
    test();

    const unsigned groupSize = 13;

    std::cout << "Biggest Group Product: "
              << calcBiggestProductGroup(num, groupSize)
              << std::endl;
    return 0;
}
