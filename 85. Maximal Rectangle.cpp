/*

9:21 - 9:31

Just transfer this problem to 84 by sum previous 1 number.

WA for this case [["0","1"],["1","0"]]

*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        reverse(heights.begin(),heights.end());
        heights.push_back(0);
        int n = heights.size();
        vector<int>maxH,leftW(n,1),rightW(n,1);
        maxH.push_back(0);
        for(int i=1;i<n;i++) {
            while(maxH.size()&&heights[maxH.back()]>=heights[i])
                maxH.pop_back();
            if(maxH.size())
                leftW[i]=i-maxH.back();
            maxH.push_back(i);
        }
        reverse(heights.begin(),heights.end());
        maxH.clear();

        maxH.push_back(0);
        for(int i=1;i<n;i++) {
            while(maxH.size()&&heights[maxH.back()]>=heights[i])
                maxH.pop_back();
            if(maxH.size())
                rightW[i]=i-maxH.back();
            maxH.push_back(i);
        }
        reverse(leftW.begin(),leftW.end());
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans,heights[i]*(rightW[i]+leftW[i]-1));
        }
        return ans;
    }
};