/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true; 

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break; 
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    std::string s = "newuzbekistan";
    std::vector<std::string> wordDict = {"new", "uzbekistan"};

    Solution solution;
    bool result = solution.wordBreak(s, wordDict);

    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}
