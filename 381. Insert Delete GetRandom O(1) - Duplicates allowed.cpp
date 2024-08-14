/**
wa x 2
swap have error.
add the second of nums to record the internal index.


 */
class RandomizedCollection {
private:
    // num-><index in the vector>, and the size

    unordered_map<int, vector<int>>numToIndexes;
    vector<pair<int, int>>nums; // val and index in map.

public:
    RandomizedCollection() {

    }
    bool insert(int val) {
        bool resp = false;
        if (numToIndexes.find(val)==numToIndexes.end()) {
            numToIndexes[val]=vector<int>();
            resp = true;
        }
        numToIndexes[val].push_back(nums.size());
        nums.push_back(make_pair(val, numToIndexes[val].size() - 1));
        return resp;
    };
    bool remove(int val) {
        bool resp = true;
        if (numToIndexes.find(val)==numToIndexes.end()) {
            resp = false;
            return resp;
        }
        // numToIndexes[val].back()
        // numToIndexes[nums.back().first][nums.back().second]
        // swap lastVal to end of numToIndexes
        swap(numToIndexes[val].back(),
            numToIndexes[nums.back().first][nums.back().second]);
        swap(nums[numToIndexes[val].back()],
            nums[numToIndexes[nums.back().first][nums.back().second]]);
        nums.pop_back();
        numToIndexes[val].pop_back();
        if (numToIndexes[val].size() == 0){
            numToIndexes.erase(val);
        }
        return resp;
    }
    int getRandom() {
        return nums[rand()%nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */