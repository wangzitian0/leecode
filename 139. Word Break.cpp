/**
1 hours

 */


class Solution {
private:
    static const long long hsBase = 197;
    static const long long hsMod = 0x7FFFFFFF;
    vector<long long> power;

    // 初始化 power 数组，存储 hsBase 的幂次
    void init(int n) {
        power.resize(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * hsBase) % hsMod;
        }
    }

    struct Str {
        vector<long long> hash;
        int len = 0;

        Str(const string& str, const vector<long long>& power) {
            // 计算字符串的前缀哈希值
            long long hs = 0;
            hash.push_back(hs);
            for (int i = 0; i < str.size(); ++i) {
                hs = (hs * hsBase + str[i]) % hsMod;
                hash.push_back(hs);
            }
            len = str.size();
        }

        // 计算子串 [s, t) 的哈希值
        long long getHash(int s, int t, const vector<long long>& power) const {
            long long result = (hash[t] - (hash[s] * power[t - s]) % hsMod + hsMod) % hsMod;
            return result;
        }

        // 获取整个字符串的哈希值
        long long getHash(const vector<long long>& power) const {
            return getHash(0, len, power);
        }
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        init(s.size());  // 初始化 power 数组
        vector<Str> wordStr;
        for (const string& word : wordDict) {
            wordStr.emplace_back(word, power);  // 构建词典中每个单词的哈希结构
        }
        Str sStr(s, power);  // 构建目标字符串的哈希结构
        vector<bool> matched(s.size() + 1, false);
        matched[0] = true;

        // 动态规划遍历字符串
        for (int i = 1; i <= s.size(); i++) {
            for (const Str& cur : wordStr) {
                if (i >= cur.len && matched[i - cur.len]) {
                    long long wordHash = cur.getHash(power);  // 词典中单词的哈希值
                    long long subStrHash = sStr.getHash(i - cur.len, i, power);  // 目标字符串中子串的哈希值
                    cout << "Comparing hashes: " << wordHash << " == " << subStrHash << endl;
                    if (wordHash == subStrHash) {  // 如果哈希值相等，表示匹配
                        matched[i] = true;
                        break;
                    }
                }
            }
        }
        return matched[s.size()];  // 返回是否可以成功分割
    }
};