class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            char C = s[0];
            s.erase(0,1);
            s.push_back(C);
            if(s == goal) return true;
        }
        return false;
    }
};