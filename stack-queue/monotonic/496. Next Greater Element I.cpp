class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono;
        map<int,int> mpp;

        for(int i=nums2.size()-1; i>=0; i--){
            mpp[nums2[i]] = -1;

            while(!mono.empty() && mono.top()<=nums2[i]) mono.pop();
            if(!mono.empty()) mpp[nums2[i]]=mono.top();
            mono.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x : nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};