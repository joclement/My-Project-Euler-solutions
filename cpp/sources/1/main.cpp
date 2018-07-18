#include <iostream>

int calcSumofMultiples(int base1, int base2, int limit)
{
    int sum = 0;

    for (int i = 0; i < limit; ++i) {
        if ((i % base1 == 0) != (i % base2 == 0)) {
            sum += i;
        }
    }

    return sum;
}

int main(int argc, char *argv[])
{
    int sum = calcSumofMultiples(3, 5, 1000);
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
