/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int superPow(int a, std::vector<int>& b) {
        const int mod = 1337;
        a %= mod; 

        int result = 1;

        for (int digit : b) {
            result = (powMod(result, 10) * powMod(a, digit)) % mod;
        }

        return result;
    }

private:
    int powMod(int base, int exponent) {
        const int mod = 1337;
        int result = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exponent /= 2;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int a = 2;
    std::vector<int> b = {1, 0};

    int result = solution.superPow(a, b);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
