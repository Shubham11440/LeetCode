class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rs = 0;

        for(int i=0;i<n;i++){
            rs = rs + nums[i];
        }

        int ls = 0;
        for(int i=0;i<n;i++){
            rs = rs - nums[i];
            if(ls == rs){
                return i;
            }
            ls = ls + nums[i];
        }
        return -1;
    }
};