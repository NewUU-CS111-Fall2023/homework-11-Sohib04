/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generatePrimesGreaterThanN(int n, int& prime1, int& prime2) {
    int current = n + 1;

    while (!isPrime(current)) {
        ++current;
    }
    prime1 = current;

    do {
        ++current;
    } while (!isPrime(current));
    prime2 = current;
}

int main() {
    int n;
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    int prime1, prime2;
    generatePrimesGreaterThanN(n, prime1, prime2);

    std::cout << "Two prime numbers greater than " << n << " are: " << prime1 << " and " << prime2 << std::endl;

    return 0;
}
