#include <cassert>
#include <iostream>
#include <vector>

/**
 * Compute the n-th prime number.
 */

bool isDividable(const unsigned divident, const std::vector<unsigned>divisors)
{
    for (std::vector<unsigned>::const_iterator divisor = divisors.begin();
            divisor != divisors.end(); ++divisor)
    {
        if(divident % *divisor == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned calcNthPrime(const unsigned n)
{
    std::vector<unsigned> primes;
    primes.push_back(2);
    primes.push_back(3);
    // primes.setCapacity(n);
    while(primes.size() < n)
    {
        bool foundNewPrime = false;
        unsigned newPrime = primes[primes.size() - 1];
        while (!foundNewPrime)
        {
            newPrime += 2;
            if (!isDividable(newPrime, primes))
            {
                foundNewPrime = true;
            }
        }
        primes.push_back(newPrime);
    }

    return primes[n - 1];
}

void test()
{
    assert(calcNthPrime(1) == 2);
    assert(calcNthPrime(2) == 3);
    assert(calcNthPrime(3) == 5);
    assert(calcNthPrime(4) == 7);
    assert(calcNthPrime(5) == 11);
    assert(calcNthPrime(6) == 13);
    assert(calcNthPrime(7) == 17);
    assert(calcNthPrime(8) == 19);

    std::cout << "Test was successful" << std::endl;
}

int main(int argc, char *argv[])
{
    test();

    unsigned n = 10001;
    std::cout << "The prime number of n = " << n << " is : "
              << calcNthPrime(n) << std::endl;

    return 0;
}
