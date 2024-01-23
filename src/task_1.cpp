/*
 * Date: 23/01/2024
 * Name: Abdimannabov Sohibjon
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int findWaysToEvaluateToTarget(vector<int>& nums, int target) {
        unordered_map<string, int> memo;

        return evaluateExpression(nums, target, 0, 0, memo);
    }

private:
    int evaluateExpression(const vector<int>& nums, int target, int index, int currentSum, unordered_map<string, int>& memo) {
        if (index == nums.size()) {
            return (currentSum == target) ? 1 : 0;
        }

        string key = to_string(index) + "_" + to_string(currentSum);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int waysWithPlus = evaluateExpression(nums, target, index + 1, currentSum + nums[index], memo);
        int waysWithMinus = evaluateExpression(nums, target, index + 1, currentSum - nums[index], memo);

        memo[key] = waysWithPlus + waysWithMinus;

        return memo[key];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution solution;
    int result = solution.findWaysToEvaluateToTarget(nums, target);

    cout << "Number of ways: " << result << endl;

    return 0;
}
