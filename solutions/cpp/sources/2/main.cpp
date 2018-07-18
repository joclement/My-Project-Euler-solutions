#include <iostream>

int calcSumofEvenFibonaccis(unsigned limit)
{
    unsigned fibo1 = 1;
    unsigned fibo2 = 2;
    unsigned sum = 2;
    unsigned nextFibo;

    while((nextFibo = fibo1 + fibo2) < limit)
    {
        fibo1 < fibo2 ? fibo1 = nextFibo : fibo2 = nextFibo;
        if(nextFibo % 2 == 0)
        {
            sum += nextFibo;
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    unsigned limit = 4000000;
    unsigned sum = calcSumofEvenFibonaccis(limit);
    std::cout << "Sum of even Fibonaccis below " << limit << " is: "
              << sum << std::endl;
    return 0;
}
