class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;  

        vector<string> bucket(s.size() + 1);  

        for (auto& it : freq) {
            bucket[it.second] += string(it.second, it.first);
        }

        string result;
        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty()) {
                result += bucket[i];
            }
        }

        return result;
    }
};