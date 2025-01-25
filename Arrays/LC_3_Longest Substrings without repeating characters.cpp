class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int maxLength = 0; 
        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            if (charIndex[s[end]] >= start) {
                start = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
