class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> SumCount;
        SumCount[0] = 1;

        int count = 0, currSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (SumCount.find(currSum - k) != SumCount.end()) {
                count += SumCount[currSum - k];
            }

            SumCount[currSum]++;
        }

        return count;
    }
};
