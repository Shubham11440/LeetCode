class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int elt1 = INT_MIN, elt2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (cnt1 > 0 && nums[i] == elt1) {
                cnt1++;
            } else if (cnt2 > 0 && nums[i] == elt2) {
                cnt2++;
            } else if (cnt1 == 0) {
                elt1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                elt2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == elt1) cnt1++;
            else if (nums[i] == elt2) cnt2++;
        }

        int mini = n / 3;
        if (cnt1 > mini) ls.push_back(elt1);
        if (cnt2 > mini) ls.push_back(elt2);

        return ls;
    }
};
