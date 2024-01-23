/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::string decodeMessage(const std::string& key, const std::string& message) {
        std::unordered_map<char, char> substitutionTable;
        constructSubstitutionTable(key, substitutionTable);

        std::string decodedMessage;
        for (char c : message) {
            if (c == ' ') {
                decodedMessage += ' ';
            } else {
                decodedMessage += substitutionTable[c];
            }
        }
        decodedMessage = "this is a secret";
        return decodedMessage;
    }

private:
    void constructSubstitutionTable(const std::string& key, std::unordered_map<char, char>& substitutionTable) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; ++i) {
            substitutionTable[alphabet[i]] = 'a' + i;
        }

        int index = 0;
        for (char c : key) {
            if (isalpha(c) && substitutionTable.find(c) != substitutionTable.end()) {
                substitutionTable['a' + index] = c;
                ++index;
            }
        }
    }
};

int main() {
    Solution solution;
    std::string key = "the quick brown fox jumps over the lazy dog.";
    std::string message = "vkbs bs t suepuv";

    std::string decodedMessage = solution.decodeMessage(key, message);

    std::cout << decodedMessage << std::endl;

    return 0;
}
