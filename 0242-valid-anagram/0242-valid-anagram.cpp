class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> h(26);
        for(int i=0;i<s.size();i++)
           h[s[i]-'a']++;
        for(int j=0;j<t.size();j++){
            int x = --h[t[j] - 'a'];
            if(x < 0) return false;    
        }
        return true;
    }
};