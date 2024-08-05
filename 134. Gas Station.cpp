/**
        // 19:09 - 19:19

        // gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        // delta = -2,-2,-2,3,3
        // -2,-2,-2,3,3,-2,-2,-2,3,3 repeat them to handle the loop.
        two pointer, if sum < 0, then move the first until sum >= 0.
        as long as the end post - start pos == n, it was a correct ans.
        if end position > 0, no effect.
        if end position < 0, it will find the start pos(which is the first position that make sure sum > 0),
        it would be the longest seq.


 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>delta;
        for(int i = 0; i < gas.size(); i++) {
            delta.push_back(gas[i] - cost[i]);
        }
        for(int i = 0; i < gas.size(); i++) {
            delta.push_back(delta[i]);
        }
        int lastIndex = -1, sum = 0;
        for(int i = 0; i < delta.size(); i++) {
            sum += delta[i];
            while(sum < 0) {
                sum -= delta[++lastIndex];
            }
            if (i - lastIndex >= gas.size()) {
                return lastIndex + 1;
            }
        }
        return -1;
    }
};