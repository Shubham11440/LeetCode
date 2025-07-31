class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
       int count = 0;
       int temp;

       for(int i=0;i<n;i++){
           if(nums[i] != 0){
             temp = nums[i];
             nums[i] = nums[count];
             nums[count] = temp;
             count++;
           }
       }
    }
};