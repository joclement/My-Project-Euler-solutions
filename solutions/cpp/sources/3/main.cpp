#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Idea: 1. compute root of num
 *       2. compute primes below root
 *       3. divide by primes until num itself is a prime.
 */

unsigned getRoundedUpRoot(unsigned long num)
{
    double root = std::sqrt(num);
    return static_cast<unsigned>(root) + 1;
}

bool isDividable(unsigned divident, std::vector<unsigned> divisors)
{
    bool dividable = false;

    for(std::vector<unsigned>::iterator it = divisors.begin();
            it != divisors.end() && !dividable; ++it)
    {
        if(divident % *it == 0)
        {
            dividable = true;
        }
    }

    return dividable;
}

std::vector<unsigned> getListOfPrimes(unsigned limit)
{
    std::vector<unsigned> primes = {2, 3};

    for (unsigned possiblePrime = 5; possiblePrime <= limit;
            possiblePrime += 2) {

        if(!isDividable(possiblePrime, primes))
        {
            primes.push_back(possiblePrime);
        }
    }

    return primes;
}

bool isPrime(unsigned num)
{
    unsigned root = getRoundedUpRoot(num);
    std::vector<unsigned> primes = getListOfPrimes(root);
    return !isDividable(num, primes);
}


unsigned calcLargestPrimeFactor(unsigned long num)
{
    std::cout << "do it for: " << num << std::endl;

    unsigned root = getRoundedUpRoot(num);
    std::cout << "root: " << root << std::endl;

    std::vector<unsigned> primes = getListOfPrimes(root);

    std::sort(primes.begin(), primes.end());

    std::vector<unsigned> primeFactors;
    for(std::vector<unsigned>::reverse_iterator it = primes.rbegin();
            it != primes.rend(); ++it)
    {
        unsigned possiblePrimeFactor = *it;
        if (num % possiblePrimeFactor == 0)
        {
            double partner = static_cast<double>(num) /
                             static_cast<double>(possiblePrimeFactor);

            if(static_cast<unsigned>(partner) == partner
                    && partner > possiblePrimeFactor
                    && isPrime(partner))
            {
                std::cout << "result partner: " << partner << std::endl;
                primeFactors.push_back(partner);
            }
            std::cout << "result of list: " << possiblePrimeFactor << std::endl;
            primeFactors.push_back(possiblePrimeFactor);
        }
    }

    std::sort(primeFactors.begin(), primeFactors.end());
    if(primeFactors.empty())
    {
        return num;
    }
    std::cout << "result: " << primeFactors.back() << std::endl;
    return primeFactors.back();
}

void test()
{
    assert(calcLargestPrimeFactor(2) == 2);
    assert(calcLargestPrimeFactor(3) == 3);
    assert(calcLargestPrimeFactor(4) == 2);
    assert(calcLargestPrimeFactor(5) == 5);
    assert(calcLargestPrimeFactor(6) == 3);
    assert(calcLargestPrimeFactor(7) == 7);
    assert(calcLargestPrimeFactor(8) == 2);
    assert(calcLargestPrimeFactor(9) == 3);
    assert(calcLargestPrimeFactor(10) == 5);
    assert(calcLargestPrimeFactor(100) == 5);
    assert(calcLargestPrimeFactor(221) == 17);
    assert(calcLargestPrimeFactor(188071) == 37);
    assert(calcLargestPrimeFactor(5083) == 23);
    assert(calcLargestPrimeFactor(8177) == 37);
    assert(calcLargestPrimeFactor(13195) == 29);
}

int main(int argc, char *argv[])
{
    test();

    unsigned long num = 600851475143;
    unsigned largestPrimeFactor = calcLargestPrimeFactor(num);
    std::cout << "Largest prime factor of " << num << " is: "
              << largestPrimeFactor << std::endl;

    return 0;
}
