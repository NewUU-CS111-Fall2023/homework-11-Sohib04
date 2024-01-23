/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <cmath>

int eulerTotientFunction(int p, int q) {
    return (p - 1) * (q - 1);
}

bool areCoprime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    int p, q;

    std::cout << "Enter the first prime number (p): ";
    std::cin >> p;

    std::cout << "Enter the second prime number (q): ";
    std::cin >> q;

    if (p <= 1 || q <= 1) {
        std::cerr << "Please enter valid prime numbers greater than 1." << std::endl;
        return 1;
    }

    int n = p * q;
    int phi_n = eulerTotientFunction(p, q);

    int e;
    for (e = 2; e < phi_n; ++e) {
        if (areCoprime(e, phi_n)) {
            break;
        }
    }

    int d = modInverse(e, phi_n);

    std::cout << "Public key (e, n): (" << e << ", " << n << ")" << std::endl;
    std::cout << "Private key (d, n): (" << d << ", " << n << ")" << std::endl;

    return 0;
}
