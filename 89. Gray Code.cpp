/*
9:28 - 9:42


*/
class Solution {
    // recusivily reverse with different 0/1 prefix?
public:
    vector<int> grayCode(int n) {
        vector<int>ans={0};
        for(int round=1;round<=n;round++){
            int po = (1<<(round-1));
            for(int i=0;i<po;i++) {
                ans.push_back(po|ans[po-1-i]);
            }
        }
        return ans;
    }
};