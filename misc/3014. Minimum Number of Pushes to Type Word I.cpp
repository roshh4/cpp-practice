class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0, i = 1;
        while(n > 0){
            int ussy = min(8, n);
            ans += ussy * i;
            i += 1;
            n -= 8;
        }
        return ans;
    }
};