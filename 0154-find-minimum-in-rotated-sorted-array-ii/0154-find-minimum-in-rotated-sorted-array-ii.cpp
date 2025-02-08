class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum must be on the right side
                low = mid + 1;
            } 
            else if (nums[mid] < nums[high]) {
                // Minimum is on the left side, including mid
                high = mid;
            } 
            else {
            // When nums[mid] == nums[high], we cannot determine the minimum, so we reduce high
                high--;
            }
        }
        return nums[low];  // or nums[high], both will be the minimum
    }
};
