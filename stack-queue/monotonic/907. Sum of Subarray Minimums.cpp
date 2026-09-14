class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        stack<int> mono;
        vector<int> res(arr.size());
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!mono.empty() && mono.top() >= arr[i]) mono.pop();
            res[i] = mono.empty()? arr.size() : mono.top();
            mono.push(i);
        }
        return res;
    }

    vector<int> findPSE(vector<int> &arr){
        stack<int> mono;
        vector<int> res(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(!mono.empty() && mono.top() > arr[i]) mono.pop();
            res[i] = mono.empty()? -1 : mono.top();
            mono.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse, pse;
        nse = findNSE(arr);
        pse = findPSE(arr);
        long long total = 0;
        long long mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - nse[i];
            long long right = pse[i] - i;
            total += ((left * right)%mod  * arr[i]) % mod;
        }
        return total%mod;
    }
};