class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int L = 0, R = 0, maxLen = 0, dupCnt = 0;
        int kAllowed = 1;

        while(R < s.size()) { 
            freq[s[R]]++;
            if (freq[s[R]] > kAllowed) dupCnt++;
            while(dupCnt > 0) {
                freq[s[L]]--;
                if (freq[s[L]] == kAllowed) dupCnt--;
                L++;
            }
            maxLen = max(maxLen, R - L + 1);
            R++;
        }
        return maxLen;
    }
};
