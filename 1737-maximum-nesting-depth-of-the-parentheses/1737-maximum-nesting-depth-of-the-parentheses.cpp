class Solution {
public:
    int maxDepth(string s) {
       int res=0, arr=0;
       for(char& c: s){
          if (c == '(')
            res = max(res, ++arr);
          if (c == ')')
            arr--;
       } 
       return res;
    }
};