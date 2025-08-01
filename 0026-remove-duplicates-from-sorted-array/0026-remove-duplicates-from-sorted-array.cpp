class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
        if(n == 0) return {};

        int res = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[res - 1]) {
                nums[res] = nums[i];
                res++;
            }
        }
        
        return res;
    }
};