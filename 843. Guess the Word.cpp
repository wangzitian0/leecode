/*
Very very hard problem.
first try: make sure no conflict with previous answers.
second try: a good try=>current string have good connect with others=>distribution of 0123456 on average
=>sum(pow(match_chars)) as min as possible or let max(match_chars) as min as possible.
I take a look at solution: most solution are wrong, use a 'random' like words[size()/2],
I tried words[random()%size], which can not pass.

*/
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
// for len=1, a...z, guess 26 times
// for len=2 aa...zz, 0->bb....zz, 1->a?, ?a, 2->ans
// for len=3 aaa...zzz, 0->bbb...zzz, 1->a??,??a,?a?, 2->aa?, a?a, ?aa, 3->ans
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        map<string, int> records;
        while (true) {
            vector<pair<int, string>> scoreToStr;
            for (int i = 0; i < words.size(); i++) {
                int score[7] = {};
                for (int j = 0; j < words.size(); j++) {
                    int s = 0;
                    for (int k = 0; k < 6; k++) {
                        if (words[i][k] == words[j][k]) {
                            s++;
                        }
                    }
                    score[s]++;
                }
                int gScore = 0;
                for (int k = 0; k < 7; k++) {
                    gScore +=score[k] * score[k];
                }
                scoreToStr.push_back(make_pair(gScore, words[i]));
            }
            sort(scoreToStr.begin(), scoreToStr.end());
            for (int i = 0; i < words.size(); i++) {
                words[i] = scoreToStr[i].second;
            }

            for (int i = 0; i < words.size(); i++) {
                string cur = words[i];
                if (records.find(cur) != records.end()) {
                    continue;
                }
                bool conflicted = false;
                for (auto record : records) {
                    int s = 0;
                    for (int k = 0; k < 6; k++) {
                        if (cur[k] == record.first[k]) {
                            s++;
                        }
                    }
                    if (s != record.second) {
                        conflicted = true;
                        break;
                    }
                }
                if (!conflicted) {
                    records[cur] = master.guess(cur);
                    swap(words[i], words[words.size() - 1]);
                    words.pop_back();
                    if (records[cur] == 6)
                        return;
                }
            }
        }
    }
};