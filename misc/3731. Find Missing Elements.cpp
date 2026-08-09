class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(int i : nums){
            minNum = min(minNum, i);
            maxNum = max(maxNum, i);
        }

        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> res;

        for(int i = minNum; i <= maxNum; i++){
            if(seen.count(i) == 0) res.push_back(i);
        }
        return res;
    }
};