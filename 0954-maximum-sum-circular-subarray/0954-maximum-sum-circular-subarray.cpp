class Solution {
public:
    int kadaneMax(vector<int>& nums) {
        int maxSoFar = nums[0], currMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSoFar = max(maxSoFar, currMax);
        }
        return maxSoFar;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int maxNormal = kadaneMax(nums);

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            nums[i] = -nums[i];
        }

        int invertedKadane = kadaneMax(nums);
        int maxCircular = totalSum + invertedKadane;

        if (maxCircular == 0) return maxNormal;

        return max(maxNormal, maxCircular);
    }
};
