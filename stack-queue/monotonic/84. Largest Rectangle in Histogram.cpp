class Solution {
public:

    void makeNSE(vector<int>& heights,vector<int>& NSE){
        stack<int> mono;

        for(int i=heights.size()-1; i>=0; i--){
            while(!mono.empty() && heights[mono.top()] >= heights[i]) mono.pop();
            NSE[i]=!mono.empty()? mono.top() : heights.size();
            mono.push(i);
        }
    }

    void makePSE(vector<int>& heights,vector<int>& PSE){
        stack<int> mono;

        for(int i=0; i<heights.size(); i++){
            while(!mono.empty() && heights[mono.top()] >= heights[i]) mono.pop();
            PSE[i]=!mono.empty()? mono.top() : -1;
            mono.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int total=0;
        vector<int> NSE(heights.size());
        vector<int> PSE(heights.size());

        makeNSE(heights,NSE);
        makePSE(heights,PSE);

        for(int i=0; i<heights.size(); i++){
            total = max(heights[i] * (NSE[i]-PSE[i]-1), total);
        }
        return total;
    }
};