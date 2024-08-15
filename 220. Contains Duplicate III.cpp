// 20:04 - 20:40
// forget how to wirte the lower_bound...
// check the doc for 20min.
// so it is that it=[map.lower_bound(key), map.upper_bound(key)) would travel all key.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        map<int, int> numAndCount;
        for (int i = 0; i < nums.size(); i++) {
            if (i > indexDiff) {
                numAndCount[nums[i - indexDiff - 1]]--;
                if (numAndCount[nums[i - indexDiff - 1]] == 0) {
                    numAndCount.erase(nums[i - indexDiff - 1]);
                }
                cout<<"erase->"<<nums[i - indexDiff - 1]<<endl;
            }
            map<int, int>::iterator it = numAndCount.lower_bound(nums[i]);
            if (it != numAndCount.end()) {
                cout <<numAndCount.size()<<"=>"<< it->first << endl;
                if (abs(it->first - nums[i]) <= valueDiff) {
                    return true;
                }
            }
            if (it != numAndCount.begin()) {
                it--;
                cout <<numAndCount.size()<<"->"<< it->first << endl;
                if (abs(it->first - nums[i]) <= valueDiff) {
                    return true;
                }
            }
            numAndCount[nums[i]] = 1;
        }
        return false;
    }
};