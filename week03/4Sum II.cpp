class Solution {
public:
     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> pairwise_sum;
        for (auto &x : nums1) {
            for (auto &y : nums2) {
                pairwise_sum[x + y]++;
            }
        }
        int tuple_cnt = 0;
        for (auto &x : nums3) {
            for(auto &y : nums4) {
                if(pairwise_sum.count(-(x + y))) {
                    tuple_cnt += pairwise_sum[-(x + y)];
                }
            }
        }
        return tuple_cnt;
    }
};
