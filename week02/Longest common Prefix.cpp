class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string firstString = strs[0], lastString = strs.back();

        int i;
        for(i = 0; i < min(firstString.size(), lastString.size()); i++) {
            if(firstString[i] != lastString[i]) break;
        }
            
        return firstString.substr(0, i);
    }
};
