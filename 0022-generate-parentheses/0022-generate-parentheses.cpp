class Solution {
public:
    void generateParanthesesisHelper(int open_rem, int close_rem, string s, vector<string> &ans){
        if(open_rem == 0 && close_rem == 0){
            ans.push_back(s);
            return;
        }
        if(open_rem > 0){
            string curr = s + '('; 
            generateParanthesesisHelper(open_rem-1, close_rem, curr, ans);
        }
        if(open_rem < close_rem){
            string curr = s + ')'; 
            generateParanthesesisHelper(open_rem, close_rem - 1, curr, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generateParanthesesisHelper(n, n, s, ans);
        return ans;
    }
};