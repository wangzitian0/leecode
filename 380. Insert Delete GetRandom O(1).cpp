/**
30min
wa many times

The idea is very simple, just use a O(1) map to record the index and a vector to record the number.
got rand from vector, then maintaince the indexes.
// wa 1&2: swap operation was wrong. the index will missing.
// wa 3: it was a set not a repeated map..


 */
class RandomizedSet {
private:
    unordered_map<int, int> numToIndex;
    vector<pair<int, int>> nums; // <number, count>

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (numToIndex.find(val) != numToIndex.end()) {
            // wa3
            // nums[numToIndex[val]].second++;
            return false;
        }
        numToIndex[val] = nums.size();
        nums.push_back(make_pair(val, 1));
        return true;
    }

    bool remove(int val) {
        if (numToIndex.find(val) != numToIndex.end()) {
            nums[numToIndex[val]].second--;
            if (nums[numToIndex[val]].second == 0) {
                // wa2
                numToIndex[nums[nums.size() - 1].first] = numToIndex[val];
                swap(nums[nums.size() - 1], nums[numToIndex[val]]);
                nums.pop_back();
                // wa1
                numToIndex.erase(val);
            }
            return true;
        }
        return false;
    }

    int getRandom() {
        int z = rand() % nums.size();
        swap(numToIndex[nums[0].first], numToIndex[nums[z].first]);
        swap(nums[0], nums[z]);
        return nums[0].first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */